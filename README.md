# clock_svg
Generate SVG clock

To copile:

    make

To run:

    ./clock_svg
  
  or
  
    ./clock_svg 7
  
  or
  
    ./clock_svg 7 13

To save into a file:

    ./clock_svg 7 13 > clock_7_13.svg

To change the colour:

    ./clock_svg --colour=pink 7 13
  
  or to change only face colour
  
    ./clock_svg --facecolour=yellow 7 13
  
  or to change only colour of hands
  
    ./clock_svg --handcolour=red 7 13

  or to change colour of hands to a different colour each
  
    ./clock_svg --minutehandcolour=yellow --hourhandcolour=red 7 13

Last colour applied will take presedence, all colours acceptable by the SVG fill attribute are acceptable.

  see also: https://developer.mozilla.org/en-US/docs/Web/SVG/Reference/Attribute/fill
