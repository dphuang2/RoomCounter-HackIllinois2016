# *Room Counter*

This is a github repository for Hack Illinois
The site for this project is live at <a> resumepipe.web.engr.illinois.edu </a>
Total time spent: **18** Hours
_____________________________________________

## **Goal**
  The goal of this project was to provide an automated occupancy count of a building or room that can be accessed wirelessly through a website.

## **Real World Application**
  The principle idea is to be able to detect and track the number of people entering and leaving a room in a given building (for now, the building of choice is ECEB). This tracker device would be placed in all rooms in the building. The number of people present in each given room would be sent to a website and displayed for everyone to see. The website would include floor maps for the building with the number of people within the room listed on the map for each room. For the future, all buildings on the University of Illinois campus could be included on the website, giving a bigger scope for the student. This would allow students to have a live feed for any available study rooms in the buildings of their choice. Something similar is present for EWS stations but those are very limited.

## **Materials used**
<ol>
  <li> Intel Edison Board </li>
  <li> Flex Sensor </li>
  <li> Touch Sensor </li>
  <li> Website with cPanel </li>
  We used PhP, jQuery, and MySQL
</ol>

## **Problems Encountered during development (It was a frustrating hack)**
  Everything...jk. But really...we were not familiar with the Edison board and Grove Base Shield v2 so that slowed us down at the beginning of development. After we got basic functionalities like shining an LED using a touch sensor, we moved on to sending a POST request to the website that we made. Implementing the POST request was by far the most difficult part of the project because we were not familiar with HTTP requests using Arduino software. We spent 11 hours getting the Arduino board to send an HTTP request to our database that would update the occupancy of the respective building/room. Some underlying issues turned out to be stating "Content-Type: " of POST request, figuring out the process of Arduino HTTP requests, and debugging the website POST .php file. After we got the HTTP requests to work, moving forward was much easier as the last things to do were to hook up the sensors and code them accordingly, and code the front-end refresh button for the website. One issue that we ran into in the last portion of the development is finding out that reading from the touch sensor twice in the same void loop() broke the Arduino code.

## **Images**
  <a href="http://imgur.com/JDOW1we"><img src="http://i.imgur.com/JDOW1we.jpg" title="source: imgur.com" /></a>
  <a href="http://imgur.com/YgVllPd"><img src="http://i.imgur.com/YgVllPd.jpg" title="source: imgur.com" /></a>
  <a href="http://imgur.com/dCIWA6T"><img src="http://i.imgur.com/dCIWA6T.jpg" title="source: imgur.com" /></a>
  <a href="http://imgur.com/PxmV1sv"><img src="http://i.imgur.com/PxmV1sv.jpg" title="source: imgur.com" /></a>
  <a href="http://imgur.com/jfXnzhs"><img src="http://i.imgur.com/jfXnzhs.gif" title="source: imgur.com" /></a>


## **Authors**
<ul>
    <li> Harsh Modhera (hmodhe2) </li>
    <li> Daniel Zhang (dzhang54) </li>
    <li> Dylan Huang (dphuang2) </li>
</ul>
