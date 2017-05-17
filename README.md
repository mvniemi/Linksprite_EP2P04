# Linksprite_EP2P04
An arduino library for the Linksprite 2.04" EPaper Display using the Adafruit GFX library

Still a bit buggy, bust fundementally seems to be working. Submit an issue if you need help with it. Documentation is in the works.

If you're using an Atmel328 or similar (Arduino Uno or similar), you won't have enough memory to buffer the whole display in 4-tone, and will only be able to use monochrome. I have not been able to test full 4-tone yet (I've been able to test run half display on the uno), I will verify it's implemented right once I get ahold of a chip with more memory.

