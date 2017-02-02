# QtAppLaunch
A small application to launch other applications.

Designed to be on a keybinding this is a small app that Narrows down a list of
Applications that can be run on your system from shortcuts in
`/usr/share/applications`.

## About
I built this after a few years of working on a Mac with spotlight, and switching
to using Linux. After mainly using a Mac, I had become use to hitting
`<CMD> - <SPACE>`, to open spotlight. Then bashing in the App I want to launch
and hitting enter.

My normal Linux setup is minimal. I use openbox with Tint2. I wanted a similar
peice of functionality in this enviroment. Thats QtAppLaunch!

## Install

``` shell
# get the code!
git clone https://github.com/lightscaletech/QtAppLaunch.git
cd QtAppLaunch

# create a make file
qmake

# build it!
make

# install it! (requires root)
sudo make install
```

## Usage
This can be run from terminal by typing `applaunch`. This issn't very useful
though. If your at the terminal run your app from there!

I have set this up on my system with a keybinding using openbox. This is bound
to `<ALT> - <SPACE>` to mimic spotlight.

### Keybinding in Openbox
To add a key binding in Openbox you need to edit the `rc.xml` config file.

On my system my users Openbox config file is located at
`~/.config/openbox/rc.xml`.

In this file scroll down to the `<keyboard>` section. In here add some thing
like the following:

``` xml
<keybind key="A-space">
      <action name="Execute">
        <command>applaunch</command>
      </action>
</keybind>
```

Of course change the key attribute as you see fit. If you haven't installed the
application in your normal PATH then you will need to provide the full path to
the applaunch file on your system.

## Licence
Copyright (C) 2017 Samuel Light

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see https://www.gnu.org/licenses/gpl-3.0.html.
