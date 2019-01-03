# codeMKII

Introducting codeMKII, my encoding solution.

Current version: v1.1.0

Usage:

    For encoding: codeMK2 (--encode / -encode / -e) <input message file> <passphrase file> <output file>.
    
    For decoding: codeMK2 (--decode / -decode / -d) <input: codeMK2 encoded file> <passphrase file> <original message output file name>.

To check verison:

    codeMK2 (--version / -version /-v)

Installation:

Linux:

        git clone https://github.com/Sid-Sun/codeMKII
        cd codeMKII
        gcc -o codeMK2 codeMK2.c
        sudo mv codeMK2 /usr/bin/codeMK2
        sudo chmod 755 /usr/bin/codeMK2
        sudo chown root:root /usr/bin/codeMK2

OR:

	curl https://raw.githubusercontent.com/Sid-Sun/codeMKII/master/install-linux.sh | sh