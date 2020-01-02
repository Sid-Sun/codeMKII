curl -s https://raw.githubusercontent.com/Sid-Sun/codeMKII/master/codeMK2.c > codeMK2.c
read -r -p "Which compiler do you want to use? [gcc/clang] " response
if [[ "$response" =~ ^([gG][cC][cC]|[gG])+$ ]]
then
	gcc -o codeMK2 codeMK2.c
else
	clang -o codeMK2 codeMK2.c
fi
read -r -p "Would you like to install codeMKII system-wide (requires superuser privilages)? [y/N] " response
if [[ "$response" =~ ^([yY][eE][sS]|[yY])+$ ]]
then
    sudo mkdir -p /usr/share/codeMKII
    sudo mv codeMK2 /usr/share/codeMKII/.
    sudo chmod 755 /usr/share/codeMKII/codeMK2
    sudo chown root:root /usr/share/codeMKII/codeMK2
    sudo ln -s /usr/share/codeMKII/codeMK2 /usr/bin/codeMK2
    echo "Installed codeMK2 system-wide."
else
    mkdir -p ~/.local/share/codeMKII
    mv codeMK2 ~/.local/share/codeMKII/.
    chmod 755 ~/.local/share/codeMKII/codeMK2
    echo "alias codeMK2='~/.local/share/codeMKII/codeMK2'" >> ~/.bashrc
    source ~/.bashrc
    echo "Installed codeMKII for "$USER"."
fi
read -r -p "Do you want to delete the source code now? [y/N] " response
if [[ "$response" =~ ^([yY][eE][sS]|[yY])+$ ]]
then
	rm -f codeMK2.c
fi
echo "Enjoy!"