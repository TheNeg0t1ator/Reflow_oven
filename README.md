# Description
This is a firmware designed to load in graphs, by datapoints for example temp and time.
I made the software adaptable in the sense that you can use any display you want, just change the menus and the library.



# Parts Needed

you'll need a few simple parts, like an ssr or relay, an arduino, buttons 
and an i2c LCD character display.

# Test Graph

in the doc, you'll find a png with the default graph, this is made visually
in geogebra, and the code for the struct is this:

GraphPoints Lead_Paste[] = {
  {0, 0},
  {150, 90},
  {180, 180},
  {245, 225},
  {245, 255}
};

link to geogebra: https://www.geogebra.org/calculator/jdvmpuhz
