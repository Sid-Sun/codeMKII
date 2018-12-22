# codeMKII

Introducting codeMKII, my encoding solution.

Usage:

    For encoding: codeMK2 -e <input message file> <passphrase file> <path to output>.
    
    For decoding: codeMK2 -d <input: codeMK2 encoded file> <passphrase file> <path to original message output>.
Installation:

Linux:

        git clone https://github.com/Sid-Sun/codeMKII
        cd codeMKII
        gcc -o codeMK2 codeMK2.c
        sudo mv codeMK2 /usr/bin/codeMK2
        sudo chmod 755 /usr/bin/codeMK2
        sudo chown root:root /usr/bin/codeMK2
