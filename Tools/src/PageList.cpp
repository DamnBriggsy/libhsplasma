/* This file is part of HSPlasma.
 *
 * HSPlasma is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * HSPlasma is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with HSPlasma.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "ResManager/plResManager.h"
#include "Debug/hsExceptions.h"
#include "Debug/plDebug.h"
#include "Stream/hsStdioStream.h"
#include <string.h>
#include <time.h>
#include <sys/stat.h>

void doHelp() {
    printf("Usage: PageList filename.prp\n\n");
}

int main(int argc, char** argv) {
    if (argc < 2) {
        doHelp();
        return 0;
    }

    hsTArray<plString> fFiles;

    plDebug::Init(plDebug::kDLAll);
    plResManager rm;
    plPageInfo* page;
    for (int i=1; i<argc; i++) {
        if (argv[i][0] == '-') {
            if (argv[i][1] == '-') argv[i]++;
            if (strcmp(argv[i], "-help") == 0) {
                doHelp();
                return 0;
            }
        } else {
            fFiles.append(argv[i]);
        }
    }

    for (size_t i=0; i<fFiles.getSize(); i++) {
        try {
            page = rm.ReadPage(fFiles[i]);
        } catch (hsException& e) {
            fprintf(stderr, "%s:%lu: %s\n", e.File(), e.Line(), e.what());
            return 1;
        } catch (std::exception& e) {
            fprintf(stderr, "PrcExtract Exception: %s\n", e.what());
            return 1;
        } catch (...) {
            fprintf(stderr, "Undefined error!\n");
            return 1;
        }
        
        hsFileStream* S = new hsFileStream();
        if (!S->open(fFiles[i], fmRead)) {
            fprintf(stderr, "Error opening %s for writing!\n", fFiles[i].cstr());
            delete S;
            return 1;
        }
        S->setVer(rm.getVer());
        
        S->seek(page->getIndexStart());
        
        plKeyCollector keys;
        
        unsigned int tCount = S->readInt();
        for (unsigned int j=0; j<tCount; j++) {
            short type = S->readShort();
            if (S->getVer() == pvEoa || S->getVer() == pvHex) {
                S->readInt();
                unsigned char b = S->readByte();
                if (b != 0)
                    printf("NOTICE: Type %04hX got flag of %02hhX\n", type, b);
            }
            unsigned int oCount = S->readInt();
            for (unsigned int k=0; k<oCount; k++) {
                plKey key = new plKeyData();
				key->read(S);
				keys.add(key);
            }
        }
        
        std::vector<short> types = keys.getTypes(page->getLocation());
        
        printf("%s :: %s\n", page->getAge().cstr(), page->getPage().cstr());
        
        for(unsigned int f = 0; f < keys.countTypes(page->getLocation()); f++) {
        	printf("|---[%04X] %s\n", types[f], pdUnifiedTypeMap::ClassName(types[f]));
        	
        	std::vector<plKey> mykeys = keys.getKeys(page->getLocation(), types[f]);
        	
        	for(unsigned int ks = 0; ks < mykeys.size(); ks++) {
        		printf("|    |--- %s\n", mykeys[ks]->getName().cstr());
			}
		}
    }
}
        
