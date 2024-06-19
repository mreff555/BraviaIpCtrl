- [BraviaIpCtrl](#braviaipctrl)
# BraviaIpCtrl
An API for interfacing with Sony Bravia devices

This project is still evolving, and of course welcoming all creative input.  Here are the current potential milestones:

- Implement all functionality defined in in the command definitions
- Implement validition for all functionality.
- compile API code as a shared object.
- Add additional functionality as seperate executibles.  Possible implementations include:
  * Command line interface (a debugging CLI was temporarily implemented in the main function)
  * Various GUI remotes.
  * Schedulers
  * Apple TV support
  * Automatic identification of devices

## CLI Usage

Currently the CLI requires either two or three arguments depending on the command used

`bctl <address> <command> [value]`

- address:  The IPv4 address of the listening bravia device
- command: Discrete commands or the category of functional area you are trying to control.
- value: When required passes a specific value to the command

see the command help for more info: `bctl -h`  

## Reference:

- Command Definitions
  * https://pro-bravia.sony.net/develop/integrate/ssip/command-definitions/
  * https://help.apple.com/itc/tvpsso/#/itc870b0d0da

