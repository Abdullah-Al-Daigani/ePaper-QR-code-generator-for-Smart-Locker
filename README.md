# QR-code-generation-in-ePaper-esp32-board-for-Smart-Locker

## using an esp32 board equipped with an ePaper display to show a QR code and information for a smart locker(Parcel box)


<p align="center">
<img align="center" src="Pictures/IMG_20230715_172858.jpg" width="300" height="400" >
  </p>
 <p align="center"> 
"Front picture of the board with QR code and Information displayed"
</p>
<p align="center">
<img align="center" src="Pictures/IMG_20230715_172932.jpg" width="300" height="400" >
</p>
<p align="center">
"Back picture of the board"
</p>



this project was made for smart delivery lockers(Parcel boxes) which have a unique QR code sticker that is used to ensure that the person opening the locker to get their order is actually in front of the locker, people can take pictures of these QR codes and exploit them to steal the orders or manipulate people to go to other locations. and changing those stickers requires a lot of time and manpower, hence the low power and low cost ePaper display esp32 will make a suitable solution for all that.



the device utilized for this project is a "LILYGO_T5_V213" board which is an esp32 board equipped with an ePaper display and an embedded battery management system BMS, this board was chosen because of its low power usage, low cost and the ePaper display which retains what it displays even if the power is cut from it.




also it can be upgraded if needed to have a backup lithium battery that charges when it is connected and works if the power goes out which will help increase its uptime level and eliminate the downtime caused by power outage.



The platformio VSCode extension was used to program the device, and The library used to interface with the device is [Xinyuan-LilyGO](https://github.com/Xinyuan-LilyGO/LilyGo-T5-Epaper-Series) which was recommended by The board manufacturer to use.
As for the QR generation code, it was taken from [ricmoo](https://github.com/ricmoo/QRCode), where this code generates a QR from an input string.
