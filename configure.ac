AC_PREREQ(2.59)
AC_INIT([dasher],[4.10.1],[http://bugzilla.gnome.org/enter_bug.cgi?product=dasher])
AC_REVISION([$Id: configure.in,v])
AC_CONFIG_SRCDIR([Src/main.cc])
AC_CONFIG_HEADERS(config.h)
dnl Can't use build-aux unless we insist on IT_PROG_INTLTOOL([0.40.1])
dnl c.f. bug #323968, but e.g. Ubuntu 8.04 LTS ships with 0.37.1
dnl AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE([1.8 gnu check-news dist-bzip2])
AM_MAINTAINER_MODE

AC_PROG_MAKE_SET
IT_PROG_INTLTOOL([0.34.90])
dnl IT_PROG_INTLTOOL([0.40.1])  c.f. bug #323968

AC_DISABLE_STATIC
AC_PROG_LIBTOOL

dnl AM_ICONV

GETTEXT_PACKAGE=dasher
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE,"$GETTEXT_PACKAGE", [Gettext package])
AM_GLIB_GNU_GETTEXT

AC_PROG_CXX

AC_PROG_LD_GNU

WITHGTK2=true;

PKG_CHECK_MODULES(GLIB, glib-2.0 >= 2.6)

AC_CHECK_LIB(expat, XML_Parse,, AC_MSG_ERROR([Expat library not found.]))
AC_LANG_PUSH(C++)
AC_CHECK_FUNCS(lldiv)
AC_CHECK_FUNC(socket,,[AC_CHECK_LIB(socket,socket)])
AC_LANG_POP(C++)

AC_ARG_ENABLE(debug,
	AS_HELP_STRING([--enable-debug],[build with additional debugging checks (default is NO)]),
	 if test $withval = "no"; then
	   DEBUG=false;
	 else
	   DEBUG=true;
         fi,
         DEBUG=false)

AC_ARG_WITH([gnome],
	 AS_HELP_STRING([--with-gnome],[build GNOME documentation (default is YES)]), 
	 if test $withval = "no"; then
	   WITHGNOME=false; 
	 else
	   WITHGNOME=true;
         fi, 
	 WITHGNOME=true)

dnl Just useful for debugging
AC_ARG_WITH([gvfs],
	AS_HELP_STRING([--with-gvfs],
		[build with gvfs from gio in glib (default is YES)]),
	[],
	with_gvfs="yes")
if test $with_gvfs != "no"; then
	PKG_CHECK_MODULES(GIO, gio-2.0,
		[have_gio=true
	 	AC_DEFINE(HAVE_GIO, 1, [gio exists so use gvfs])],
		[have_gio=false])
fi

AC_ARG_ENABLE([speech],
	 AS_HELP_STRING([--enable-speech],[build with speech support (default is NO)]),
	 if test $enableval = "no"; then
	   WITHSPEECH=false; 
	 else
	   WITHSPEECH=true;
         fi, 
	 WITHSPEECH=false)

AC_ARG_WITH([qte],
	 AS_HELP_STRING([--with-qte],[build with QTE support (default is NO -- currently untested)]), 
	 if test $withval = "no"; then
	   WITHQTE=false; 
	 else
	   WITHQTE=true;
         fi, 
	 WITHQTE=false)

AC_ARG_WITH([gpe],
	 AS_HELP_STRING([--with-gpe],[build with GPE support (default is NO -- currently untested)]), 
	 if test $withval = "no"; then
	   WITHGPE=false; 
	 else
	   WITHGPE=true;
         fi, 
	 WITHGPE=false)

AC_ARG_ENABLE([a11y],
	 AS_HELP_STRING([--enable-a11y],[build with support for the GNOME accessibility framework (default is YES)]),
	 if test $enableval = "no"; then
	   WITHA11Y=false; 
	 else
	   WITHA11Y=true;
         fi, 
	 WITHA11Y=true)

AC_ARG_ENABLE([japanese],
	 AS_HELP_STRING([--enable-japanese],[build with support for Japanese Kanji entry (experimental -- default is NO)]),
	 if test $enableval = "no"; then
	   WITHJAPANESE=false; 
	 else
	   AC_CHECK_LIB(canna, RkBgnBun,, AC_MSG_ERROR([Canna library not found (required for Japanese).]))
	   WITHJAPANESE=true;
         fi, 
	 WITHJAPANESE=false)

AC_ARG_ENABLE([chinese],
	 AS_HELP_STRING([--enable-chinese],[build with support for Chinese PinYin entry (experimental -- default is NO)]),
	 if test $enableval = "no"; then
	   WITHCHINESE=false; 
	 else
	   WITHCHINESE=true;
         fi, 
	 WITHCHINESE=false)

AC_ARG_ENABLE([joystick],
	 AS_HELP_STRING([--enable-joystick],[Build with Linux joystick support (note that other UNIX based operating systems aren't supported here)]),
	 if test $enableval = "no"; then
	   WITHJOYSTICK=false; 
	 else
	   WITHJOYSTICK=true;
         fi, 
	 WITHJOYSTICK=false)


AC_ARG_ENABLE([tilt],
	 AS_HELP_STRING([--enable-tilt],[Build with experimental support for tilt sensor input (experimental -- default is NO)]),
	 if test $enableval = "no"; then
	   WITHTILT=false; 
	 else
	   WITHTILT=true;
         fi, 
	 WITHTILT=false)


AC_ARG_WITH([maemo],
	AS_HELP_STRING([--with-maemo],[build with Maemo support (default is NO)]),
	if test $withval = "yes"; then
	   WITHMAEMO=true;
	   WITHGNOME=false;
	   WITHA11Y=false;
	else
	   WITHMAEMO=false;
        fi,
	WITHMAEMO=false)

AC_ARG_WITH([maemo-fullscreen],
	AS_HELP_STRING([--with-maemo-fullscreen],[build as standalone Maemo fullscreen app (default is NO)]),
	if test $withval = "yes"; then
	   WITHMAEMOFULLSCREEN=true;
	   WITHMAEMO=true;
	   WITHGNOME=false;
	   WITHA11Y=false;
	else
	   WITHMAEMOFULLSCREEN=false;
        fi,
	WITHMAEMOFULLSCREEN=false)


dnl AC_ARG_WITH([darwin],
dnl 	AS_HELP_STRING([--with-darwin],[build with Darwin (Mac OS X) support (default is NO)]),
dnl 	if test $withval = "yes"; then
dnl 	   WITHDARWIN=true;
dnl 	else
dnl 	   WITHDARWIN=false;
dnl 	fi,
dnl 	WITHDARWIN=false)

AC_ARG_WITH([cairo],
	 AS_HELP_STRING([--with-cairo],[build with cairo support (default is YES)]),
	 if test $withval = "no"; then
	   WITHCAIRO=false; 
	 else
	   WITHCAIRO=true;
         fi, 
	 WITHCAIRO=true)

if test x"$WITHGTK2" = xtrue
then 
	PKG_CHECK_MODULES(GTK2, gtk+-2.0 >= 2.6.0,[GTK2HERE=true],[GTK2HERE=false]) 
	PKG_CHECK_MODULES(GCONF, gconf-2.0,[GCONF2HERE=true],[GCONF2HERE=false])
	if test x$GCONF2HERE = xfalse; then
		AC_MSG_WARN([GConf was not detected - user preferences will not be stored.])
	fi
	save_CFLAGS="$CFLAGS"
	save_LIBS="$LIBS"
	CFLAGS="$CFLAGS $GTK2_CFLAGS"
	LIBS="$LIBS $GTK2_LIBS"
	AC_CHECK_FUNCS([gtk_show_uri]) dnl which appeared in Gtk 2.13.1
	CFLAGS="$save_CFLAGS"
	LIBS="$save_LIBS"
fi

if test x"$GTK2HERE" = xtrue -a x"$WITHGTK2" = xtrue -a x"$WITHQTE" != xtrue
then
	BUILDGTK2=true
elif test x"$GTK2HERE" = xtrue -a x"$WITHQTE" != xtrue
then
	BUILDGTK2=true
else 
	BUILDGTK2=false
fi

if test x$BUILDGTK2 = xfalse -a x"$WITHQTE" != xtrue
then
	echo $WITHGTK2
	AC_ERROR("Unable to find GTK2 or another necessary library. See the previous line for more useful data.")
fi

if test x"$DEBUG" = xtrue; then
	AC_DEFINE([DEBUG], 1, [Additional debug checks enabled])
fi

if test x"$WITHSPEECH" = xtrue; then
	PKG_CHECK_MODULES(gnome_speech, gnome-speech-1.0 bonobo-activation-2.0 libbonobo-2.0 ORBit-2.0)
	AC_DEFINE([GNOME_SPEECH], 1, [gnome_speech-1 libraries are present])
#	SPEECH_SOURCES='speech.$(OBJEXT)'
fi

if test x"$WITHA11Y" = xtrue; then
	PKG_CHECK_MODULES(gnome_a11y, bonobo-activation-2.0 libbonobo-2.0 ORBit-2.0 libgnomeui-2.0 cspi-1.0 atk)
	AC_DEFINE([GNOME_A11Y], 1, [gnome_a11y libraries are present])
fi

if test x"$WITHQTE" != xtrue -a x"$WITHA11Y" != xtrue; then
	AC_PATH_XTRA
	if test	x$no_x = xyes ; then
		AC_MSG_ERROR([X development libraries not found])
	else
		X_LIBS="$X_LIBS $X_PRE_LIBS -lX11 $X_EXTRA_LIBS"
	fi

	save_LIBS="$LIBS"
	AC_CHECK_LIB([Xtst], [XTestFakeKeyEvent],
	             [X_LIBS="$X_LIBS -lXtst"
	              AC_DEFINE(HAVE_XTST, 1, [The XTest extension is present])],
	             [AC_MSG_ERROR([Couldn't find the Xtst library. Check config.log for details])],
	             $X_LIBS)
	LIBS="$save_LIBS"
	AC_SUBST(X_LIBS)
fi


if test x"$WITHJAPANESE" = xtrue; then
	AC_DEFINE([JAPANESE], 1, [Japanese support enabled])
	JAPANESE_SOURCES='CannaConversionHelper.$(OBJEXT)'
else
	JAPANESE_SOURCES=
fi

AC_SUBST(JAPANESE_SOURCES)

if test x"$WITHCHINESE" = xtrue; then
	AC_DEFINE([CHINESE], 1, [Chinese support enabled])
	CHINESE_SOURCES='PinYinConversionHelper.$(OBJEXT) PinyinParser.$(OBJEXT)'

else
	CHINESE_SOURCES=
fi

AC_SUBST(CHINESE_SOURCES)

if test x"$WITHJOYSTICK" = xtrue; then
	AC_DEFINE([JOYSTICK], 1, [Linux joystick support enabled])
fi

if test x"$WITHTILT" = xtrue; then
	AC_DEFINE([TILT], 1, [Tilt input support enabled])
fi

if test x"$WITHGPE" = xtrue; then
	AC_DEFINE([WITH_GPE], 1, [gpe is present])
fi

dnl if test x"$WITHDARWIN" = xtrue ; then
dnl         AC_DEFINE([WITH_DARWIN], 1, [Targeting Darwin/X11])
dnl fi

if test x"$WITHMAEMO" = xtrue; then
      AC_DEFINE([WITH_MAEMO], 1, [Maemo is present])
      dnl Yes, this sucks
      glade_LIBS="/usr/lib/libglade-2.0.a"
      PKG_CHECK_MODULES(hildon, hildon-libs)
      AC_CHECK_LIB(osso, osso_initialize,, AC_MSG_ERROR([Osso library not found.]))
fi			

if test x"$WITHMAEMOFULLSCREEN" = xtrue; then
      AC_DEFINE([WITH_MAEMOFULLSCREEN], 1, [Building as fullscreen Maemo app])
fi

if test x"$WITHCAIRO" = xtrue; then
	PKG_CHECK_MODULES(cairo, gtk+-2.0 >= 2.8.0)
	AC_DEFINE([WITH_CAIRO], 1, [use cairo (needs Gtk+ >= 2.8.0)])
fi

if test x"$BUILDGTK2" = xtrue; then 
	PKG_CHECK_MODULES(glade, libglade-2.0)
	if test x"$WITHMAEMO" = xtrue; then
	        dnl Yes, this sucks
		glade_LIBS=`echo $glade_LIBS | sed s/-lglade-2.0//`
		glade_LIBS="$glade_LIBS /usr/lib/libglade-2.0.a"
	fi

	PKG_CHECK_MODULES(gthread, gthread-2.0)


dnl	if test x"$WITHMAEMO" = xfalse; then
dnl		PKG_CHECK_MODULES(wnck, libwnck-1.0)
dnl	        AC_DEFINE([HAVE_WNCK], 1, [wnck is present])
dnl	fi
fi

# libglade's autoconnect feature requires dasher to be linked with
# the --export-dynamic flag. pkg-config does not provide it, and libtool
# knows what to do with -export-dynamic.
if test x"$glade_LIBS" != x ; then
	glade_LIBS="$glade_LIBS -export-dynamic"
fi

if test x"$GCONF2HERE" = xtrue ; then
        AM_GCONF_SOURCE_2
        AC_DEFINE([WITH_GCONF], 1, [Use GConf])
fi

AC_SUBST(gnome_speech_LIBS)
AC_SUBST(gnome_speech_CFLAGS)
AC_SUBST([SPEECH_SOURCES])

AC_SUBST(gnome_a11y_LIBS)
AC_SUBST(gnome_a11y_CFLAGS)
AC_SUBST([A11Y_SOURCES])

AC_SUBST(gnome_LIBS)
AC_SUBST(gnome_CFLAGS)

AC_SUBST(glade_LIBS)
AC_SUBST(glade_CFLAGS)

AC_SUBST(gthread_LIBS)
AC_SUBST(gthread_CFLAGS)

AC_SUBST(wnck_LIBS)
AC_SUBST(wnck_CFLAGS)

AC_SUBST(hildon_LIBS)
AC_SUBST(hildon_CFLAGS)

AC_SUBST(GETTEXT_PACKAGE)

AM_CONDITIONAL(DOGTK2, test x$BUILDGTK2 = xtrue)	
AM_CONDITIONAL(DOQTE, test x$WITHQTE = xtrue)
AM_CONDITIONAL(GNOME_SPEECH, test x$WITHSPEECH = xtrue)
AM_CONDITIONAL(GNOME_A11Y, test x$WITHA11Y = xtrue)
AM_CONDITIONAL(GNOME_HELP, test x$WITHGNOME = xtrue)
AM_CONDITIONAL(WITH_GPE, test x$WITHGPE = xtrue)
AM_CONDITIONAL(WITH_MAEMO, test x$WITHMAEMO = xtrue)
AM_CONDITIONAL(WITH_MAEMOFULLSCREEN, test x$WITHMAEMOFULLSCREEN = xtrue)
AM_CONDITIONAL(JAPANESE, test x$WITHJAPANESE = xtrue)
AM_CONDITIONAL(CHINESE, test x$WITHCHINESE = xtrue)
AM_CONDITIONAL(JOYSTICK, test x$WITHJOYSTICK = xtrue)

AC_SUBST(GTK2_CFLAGS)
AC_SUBST(GTK2_LIBS)

AC_SUBST(GCONF_CFLAGS)
AC_SUBST(GCONF_LIBS)

if test x"$WITHGPE" = xtrue ; then
	SETTINGS_CFLAGS=" "
	SETTINGS_LIBS="-lgpewidget -lXsettings-client -lXsettings"
else
	SETTINGS_CFLAGS=$GCONF_CFLAGS
	SETTINGS_LIBS=$GCONF_LIBS
fi
AC_SUBST(SETTINGS_CFLAGS)
AC_SUBST(SETTINGS_LIBS)

GTK2BUILD_CFLAGS="$GTK2_CFLAGS $GIO_CFLAGS $SETTINGS_CFLAGS $gthread_CFLAGS $gnome_speech_CFLAGS $gnome_a11y_CFLAGS $glade_CFLAGS $gnome_CFLAGS $wnck_CFLAGS $hildon_CFLAGS"

GTK2BUILD_LIBS="$X_LIBS $GTK2_LIBS $GIO_LIBS $SETTINGS_LIBS $gthread_LIBS $gnome_speech_LIBS $gnome_a11y_LIBS $glade_LIBS $gnome_LIBS $wnck_LIBS $hildon_LIBS"

AC_SUBST(GTK2BUILD_CFLAGS)
AC_SUBST(GTK2BUILD_LIBS)

AC_MSG_CHECKING([for gnome-doc-utils])
dnl Avoid default action which is to complain if not found
GNOME_DOC_INIT([0.9.0],[gdu_cv_have_gdu=yes],[gdu_cv_have_gdu=no])
AC_MSG_RESULT($gdu_cv_have_gdu)

if test x"$WITHGNOME" = xtrue -a x"$gdu_cv_have_gdu" = xno ; then
    AC_MSG_ERROR([gnome-doc-utils not found!])
fi

dnl XXX PRLW How is this better than the standard
dnl gdu_cv_have_gdu && enable_scrollkeeper ?
AM_CONDITIONAL(ENABLE_SK, test x"$WITHGNOME" = xfalse -a x"$enable_scrollkeeper" = "xyes")

AC_CONFIG_FILES([Data/dasher.desktop.in
		 Data/Makefile
		 Data/training/Makefile
		 Data/alphabets/Makefile
		 Data/glade/Makefile
		 Data/colours/Makefile
		 Data/controllabels/Makefile
		 Data/Help/Makefile
		 Data/Help/Gnome/Makefile
		 Doc/Makefile
		 Doc/user/Makefile
		 Makefile
		 Src/Makefile
		 Src/Common/Makefile
		 Src/DasherCore/Makefile
		 Src/DasherCore/LanguageModelling/Makefile
		 Src/DasherIM/Makefile
		 Src/Gtk2/Makefile
		 Src/Installer/Makefile
		 Src/InstallerTobii/Makefile
		 Src/InstallerW2K/Makefile
		 Src/Win32/Makefile
		 po/Makefile.in])

AC_OUTPUT