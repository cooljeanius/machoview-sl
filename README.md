# MachOView for Snow Leopard

Peter Saghelyi created this fantastic macho-o executable viewer/browser over on [Sourceforge](http://sourceforge.net/projects/machoview/ "Sourceforge project home").

Since I could not find a version for Snow Leopard, I decided to try and
check out the latest SF source code version that looked promising enough
to try and revert it back to a state that would let it compile and link
on Snow Leopard. 

- This meant getting rid of ARC and going back to GC.
- This also means that there are probably gonna be memory bugs. 
- Functionality-wise everything is there though. 
  Watching the console when loading binaries produces all the right 
  output and no error messages like wrong selectors etc.
- Based on r218 from Peter's Sourceforge SVN repository. 

I included a dmg with a precompiled binary in the `dist` folder.

Have fun!

_PS: the original README included with the project has been renamed to README_orig.md_

