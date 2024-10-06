
program called TAB2TAB that can do tab-to-mif and mif-to-tab translations:

Usage: tab2tab <src_filename> <dst_filename>
    Converts TAB or MIF file <src_filename> to TAB or MIF format.
    The extension of <dst_filename> (.tab or .mif) defines the output format.


COMPILING THE LIBRARY:
----------------------

The MITAB directory contains the core of the library and the TAB2TAB  conversion program.
The OGR and CPL directories are support libraries used by MITAB and probably won't be of much interest to you at the beginning.

To compile the library on Unix:
  The main directory contains a GNUmakefile


USING THE LIBRARY IN YOUR PROGRAMS:
-----------------------------------

the main classes you will need to deal with live in the header MITAB.H.


The rest of this file covers mostly the C++ API features but may also apply to the C API indirectly.


TO READ FILES:
--------------

To open a .TAB or .MIF file for read, you can use the static method:

  IMapInfoFile *IMapInfoFile::SmartOpen(const char *pszFname,
                                        GBool bTestOpenNoError);

This function returns NULL if the file cannot be opened.  If the open
was succesful, then it returns a new object of the type corresponding
to the type of file that was opened:

  class TABFile:  Class to handle .TAB datasets for read/write access.
                  Note that you cannot use it to modify exsiting datasets
                  (not yet!).

  class TABView:  Class to handle views on pairs of .TAB files linked 
                  through an indexed field of type integer.

  class MIFFile:  Class to handle MIF files for read/write.


The method IMapInfoFile::GetFileClass() can be used to establish the 
type of object that has been returned by SmartOpen().


TO CREATE NEW FILES:
--------------------

For write access, you create an instance of TABFile or MIFFile and use
it to open the new file and write to it.  Note that only sequential write is 
supported.


FEATURE CLASSES:
----------------

On read access, GetFeatureRef() returns object of classes derived from
class TABFeature.  You can tell the type of an object using the method
TABFeature::GetFeatureClass().

The following table lists the various feature types and the geometry 
types that can be returned and that are accepted (for writing) by each
of them:

    Feature Type     Returns (read mode)    Accepts (write mode)
    ------------     -------------------    --------------------

    TABPoint         OGRPoint               OGRPoint

    TABFontPoint     OGRPoint               OGRPoint

    TABCustomPoint   OGRPoint               OGRPoint

    TABPolyline      OGRLineString or       OGRLineString or
                     OGRMultilineString     OGRMultilineString

    TABRegion        OGRPolygon (with a     OGRPolygon (with 1 or more
                     single ring) or        rings) or OGRMultiPolygon
                     OGRMultiPolygon (for 
                     multiple rings)

    TABRectangle     OGRPolygon             OGRPolygon

    TABEllipse       OGRPolygon             OGRPolygon or 
                                            OGRPoint corresponding to the
                                            ellipse center

    TABArc           OGRLineString          OGRLineString or 
                                            OGRPoint corresponding to the
                                            arc's defining ellipse center

    TABText          OGRPoint (the lower-   OGRPoint
                     left corner of the
                     text)

    TABMultiPoint    OGRMultiPoint          OGRMultiPoint

    TABCollection    OGRCollection with     In write mode, the geometry
                     3 optional components: cannot be set directly as an
                     1- 0 or 1 OGRPolygon   OGRGeometry. The following methods
                        or OGRMultiPolygon  must be used instead:
                     2- 0 or 1 OGRLineString     SetRegionDirectly()
                        or OGRMultiLineString    SetPolylineDirectly()
                     3- 0 or 1 OGRMultiPoint     SetMultiPointDirectly()


NOTE ABOUT "\n" IN STRINGS ON TABText OBJECTS:
----------------------------------------------

The text strings on text object may contain embedded "\n" characters in
MapInfo.  

In those cases, the library returns strings in which the "\n" character
is escaped on two characters: "\" + "n"

The library will also automatically convert any "\"+"n" sequence in
strings into a binary "\n" when it writes text objects to TAB files.

This also implies that a single "\" character also has to be converted
to "\"+"\".

Also note that this conversion does not apply to table fields of type 
"Char" since there appears to be no special treatment in MapInfo for 
the "\n" sequence in char attribute field values.


------------
$Id: README.TXT,v 1.12 2005/10/07 14:00:07 dmorissette Exp $
------------
