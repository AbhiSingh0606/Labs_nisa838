<img src="https://github.com/ee209-2020class/ee209-2020class.github.io/blob/master/ExtraInfo/logo.png">

# Lab 6 Notes

Keep a digital log of your work using the readme file where appropriate.

Q P.1


| Digit | Segments lit | Binary |
|:-----:|:-------------|:--------|
| 0 | a b c d e f   | 0b00111111 |
| 1 | b c           | 0b00000110 | 
| 2 | a b d e g     | 0b01011011 | 
| 3 | a b c d g     | 0b01001111 |
| 4 | b c f g       | 0b01100110 |
| 5 | a c d f g     | 0b01101101 |
| 6 | a c d e f g   | 0b01111101 |
| 7 | a b c         | 0b00000111 |
| 8 | a b c d e f g | 0b01111111 |
| 9 | a b c d f g   | 0b01101111 |



Q 1.2
the segments are set before the digit is enabled so the wrong number is never shown. If the digit were enabled first, it would flash the old digit's pattern for a shprt moment, which shows as ghosting.

Q 1.3 
Only one digit can be lit at a time because they share the segment wires. Switching that fast is enough for persistence of vision so both digits look continuously lit even though only one is on at any given moment


Q 2.1

N + 8 pinss
