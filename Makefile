#############################################################################
# Makefile for building: BornAgain
# Generated by qmake (2.01a) (Qt 4.8.4) on: Thu Jul 18 15:22:28 2013
# Project:  BornAgain.pro
# Template: subdirs
# Command: /usr/bin/qmake -o Makefile BornAgain.pro
#############################################################################

first: make_default
MAKEFILE      = Makefile
QMAKE         = /usr/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
SUBTARGETS    =  \
		sub-Core \
		sub-ThirdParty-gtest \
		sub-ThirdParty-RootMathMore \
		sub-Fit \
		sub-App \
		sub-Tests-UnitTests-TestCore

Core/$(MAKEFILE): 
	@$(CHK_DIR_EXISTS) Core/ || $(MKDIR) Core/ 
	cd Core/ && $(QMAKE) /home/pospelov/development/git/BornAgain/Core/Core.pro -o $(MAKEFILE)
sub-Core-qmake_all:  FORCE
	@$(CHK_DIR_EXISTS) Core/ || $(MKDIR) Core/ 
	cd Core/ && $(QMAKE) /home/pospelov/development/git/BornAgain/Core/Core.pro -o $(MAKEFILE)
sub-Core: Core/$(MAKEFILE) FORCE
	cd Core/ && $(MAKE) -f $(MAKEFILE)
sub-Core-make_default-ordered: Core/$(MAKEFILE) FORCE
	cd Core/ && $(MAKE) -f $(MAKEFILE) 
sub-Core-make_default: Core/$(MAKEFILE) FORCE
	cd Core/ && $(MAKE) -f $(MAKEFILE) 
sub-Core-make_first-ordered: Core/$(MAKEFILE) FORCE
	cd Core/ && $(MAKE) -f $(MAKEFILE) first
sub-Core-make_first: Core/$(MAKEFILE) FORCE
	cd Core/ && $(MAKE) -f $(MAKEFILE) first
sub-Core-all-ordered: Core/$(MAKEFILE) FORCE
	cd Core/ && $(MAKE) -f $(MAKEFILE) all
sub-Core-all: Core/$(MAKEFILE) FORCE
	cd Core/ && $(MAKE) -f $(MAKEFILE) all
sub-Core-clean-ordered: Core/$(MAKEFILE) FORCE
	cd Core/ && $(MAKE) -f $(MAKEFILE) clean
sub-Core-clean: Core/$(MAKEFILE) FORCE
	cd Core/ && $(MAKE) -f $(MAKEFILE) clean
sub-Core-distclean-ordered: Core/$(MAKEFILE) FORCE
	cd Core/ && $(MAKE) -f $(MAKEFILE) distclean
sub-Core-distclean: Core/$(MAKEFILE) FORCE
	cd Core/ && $(MAKE) -f $(MAKEFILE) distclean
sub-Core-install_subtargets-ordered: Core/$(MAKEFILE) FORCE
	cd Core/ && $(MAKE) -f $(MAKEFILE) install
sub-Core-install_subtargets: Core/$(MAKEFILE) FORCE
	cd Core/ && $(MAKE) -f $(MAKEFILE) install
sub-Core-uninstall_subtargets-ordered: Core/$(MAKEFILE) FORCE
	cd Core/ && $(MAKE) -f $(MAKEFILE) uninstall
sub-Core-uninstall_subtargets: Core/$(MAKEFILE) FORCE
	cd Core/ && $(MAKE) -f $(MAKEFILE) uninstall
ThirdParty/gtest/$(MAKEFILE): 
	@$(CHK_DIR_EXISTS) ThirdParty/gtest/ || $(MKDIR) ThirdParty/gtest/ 
	cd ThirdParty/gtest/ && $(QMAKE) /home/pospelov/development/git/BornAgain/ThirdParty/gtest/gtest.pro -o $(MAKEFILE)
sub-ThirdParty-gtest-qmake_all:  FORCE
	@$(CHK_DIR_EXISTS) ThirdParty/gtest/ || $(MKDIR) ThirdParty/gtest/ 
	cd ThirdParty/gtest/ && $(QMAKE) /home/pospelov/development/git/BornAgain/ThirdParty/gtest/gtest.pro -o $(MAKEFILE)
sub-ThirdParty-gtest: ThirdParty/gtest/$(MAKEFILE) FORCE
	cd ThirdParty/gtest/ && $(MAKE) -f $(MAKEFILE)
sub-ThirdParty-gtest-make_default-ordered: ThirdParty/gtest/$(MAKEFILE) sub-Core-make_default-ordered  FORCE
	cd ThirdParty/gtest/ && $(MAKE) -f $(MAKEFILE) 
sub-ThirdParty-gtest-make_default: ThirdParty/gtest/$(MAKEFILE) FORCE
	cd ThirdParty/gtest/ && $(MAKE) -f $(MAKEFILE) 
sub-ThirdParty-gtest-make_first-ordered: ThirdParty/gtest/$(MAKEFILE) sub-Core-make_first-ordered  FORCE
	cd ThirdParty/gtest/ && $(MAKE) -f $(MAKEFILE) first
sub-ThirdParty-gtest-make_first: ThirdParty/gtest/$(MAKEFILE) FORCE
	cd ThirdParty/gtest/ && $(MAKE) -f $(MAKEFILE) first
sub-ThirdParty-gtest-all-ordered: ThirdParty/gtest/$(MAKEFILE) sub-Core-all-ordered  FORCE
	cd ThirdParty/gtest/ && $(MAKE) -f $(MAKEFILE) all
sub-ThirdParty-gtest-all: ThirdParty/gtest/$(MAKEFILE) FORCE
	cd ThirdParty/gtest/ && $(MAKE) -f $(MAKEFILE) all
sub-ThirdParty-gtest-clean-ordered: ThirdParty/gtest/$(MAKEFILE) sub-Core-clean-ordered  FORCE
	cd ThirdParty/gtest/ && $(MAKE) -f $(MAKEFILE) clean
sub-ThirdParty-gtest-clean: ThirdParty/gtest/$(MAKEFILE) FORCE
	cd ThirdParty/gtest/ && $(MAKE) -f $(MAKEFILE) clean
sub-ThirdParty-gtest-distclean-ordered: ThirdParty/gtest/$(MAKEFILE) sub-Core-distclean-ordered  FORCE
	cd ThirdParty/gtest/ && $(MAKE) -f $(MAKEFILE) distclean
sub-ThirdParty-gtest-distclean: ThirdParty/gtest/$(MAKEFILE) FORCE
	cd ThirdParty/gtest/ && $(MAKE) -f $(MAKEFILE) distclean
sub-ThirdParty-gtest-install_subtargets-ordered: ThirdParty/gtest/$(MAKEFILE) sub-Core-install_subtargets-ordered  FORCE
	cd ThirdParty/gtest/ && $(MAKE) -f $(MAKEFILE) install
sub-ThirdParty-gtest-install_subtargets: ThirdParty/gtest/$(MAKEFILE) FORCE
	cd ThirdParty/gtest/ && $(MAKE) -f $(MAKEFILE) install
sub-ThirdParty-gtest-uninstall_subtargets-ordered: ThirdParty/gtest/$(MAKEFILE) sub-Core-uninstall_subtargets-ordered  FORCE
	cd ThirdParty/gtest/ && $(MAKE) -f $(MAKEFILE) uninstall
sub-ThirdParty-gtest-uninstall_subtargets: ThirdParty/gtest/$(MAKEFILE) FORCE
	cd ThirdParty/gtest/ && $(MAKE) -f $(MAKEFILE) uninstall
ThirdParty/RootMathMore/$(MAKEFILE): 
	@$(CHK_DIR_EXISTS) ThirdParty/RootMathMore/ || $(MKDIR) ThirdParty/RootMathMore/ 
	cd ThirdParty/RootMathMore/ && $(QMAKE) /home/pospelov/development/git/BornAgain/ThirdParty/RootMathMore/RootMathMore.pro -o $(MAKEFILE)
sub-ThirdParty-RootMathMore-qmake_all:  FORCE
	@$(CHK_DIR_EXISTS) ThirdParty/RootMathMore/ || $(MKDIR) ThirdParty/RootMathMore/ 
	cd ThirdParty/RootMathMore/ && $(QMAKE) /home/pospelov/development/git/BornAgain/ThirdParty/RootMathMore/RootMathMore.pro -o $(MAKEFILE)
sub-ThirdParty-RootMathMore: ThirdParty/RootMathMore/$(MAKEFILE) FORCE
	cd ThirdParty/RootMathMore/ && $(MAKE) -f $(MAKEFILE)
sub-ThirdParty-RootMathMore-make_default-ordered: ThirdParty/RootMathMore/$(MAKEFILE) sub-ThirdParty-gtest-make_default-ordered  FORCE
	cd ThirdParty/RootMathMore/ && $(MAKE) -f $(MAKEFILE) 
sub-ThirdParty-RootMathMore-make_default: ThirdParty/RootMathMore/$(MAKEFILE) FORCE
	cd ThirdParty/RootMathMore/ && $(MAKE) -f $(MAKEFILE) 
sub-ThirdParty-RootMathMore-make_first-ordered: ThirdParty/RootMathMore/$(MAKEFILE) sub-ThirdParty-gtest-make_first-ordered  FORCE
	cd ThirdParty/RootMathMore/ && $(MAKE) -f $(MAKEFILE) first
sub-ThirdParty-RootMathMore-make_first: ThirdParty/RootMathMore/$(MAKEFILE) FORCE
	cd ThirdParty/RootMathMore/ && $(MAKE) -f $(MAKEFILE) first
sub-ThirdParty-RootMathMore-all-ordered: ThirdParty/RootMathMore/$(MAKEFILE) sub-ThirdParty-gtest-all-ordered  FORCE
	cd ThirdParty/RootMathMore/ && $(MAKE) -f $(MAKEFILE) all
sub-ThirdParty-RootMathMore-all: ThirdParty/RootMathMore/$(MAKEFILE) FORCE
	cd ThirdParty/RootMathMore/ && $(MAKE) -f $(MAKEFILE) all
sub-ThirdParty-RootMathMore-clean-ordered: ThirdParty/RootMathMore/$(MAKEFILE) sub-ThirdParty-gtest-clean-ordered  FORCE
	cd ThirdParty/RootMathMore/ && $(MAKE) -f $(MAKEFILE) clean
sub-ThirdParty-RootMathMore-clean: ThirdParty/RootMathMore/$(MAKEFILE) FORCE
	cd ThirdParty/RootMathMore/ && $(MAKE) -f $(MAKEFILE) clean
sub-ThirdParty-RootMathMore-distclean-ordered: ThirdParty/RootMathMore/$(MAKEFILE) sub-ThirdParty-gtest-distclean-ordered  FORCE
	cd ThirdParty/RootMathMore/ && $(MAKE) -f $(MAKEFILE) distclean
sub-ThirdParty-RootMathMore-distclean: ThirdParty/RootMathMore/$(MAKEFILE) FORCE
	cd ThirdParty/RootMathMore/ && $(MAKE) -f $(MAKEFILE) distclean
sub-ThirdParty-RootMathMore-install_subtargets-ordered: ThirdParty/RootMathMore/$(MAKEFILE) sub-ThirdParty-gtest-install_subtargets-ordered  FORCE
	cd ThirdParty/RootMathMore/ && $(MAKE) -f $(MAKEFILE) install
sub-ThirdParty-RootMathMore-install_subtargets: ThirdParty/RootMathMore/$(MAKEFILE) FORCE
	cd ThirdParty/RootMathMore/ && $(MAKE) -f $(MAKEFILE) install
sub-ThirdParty-RootMathMore-uninstall_subtargets-ordered: ThirdParty/RootMathMore/$(MAKEFILE) sub-ThirdParty-gtest-uninstall_subtargets-ordered  FORCE
	cd ThirdParty/RootMathMore/ && $(MAKE) -f $(MAKEFILE) uninstall
sub-ThirdParty-RootMathMore-uninstall_subtargets: ThirdParty/RootMathMore/$(MAKEFILE) FORCE
	cd ThirdParty/RootMathMore/ && $(MAKE) -f $(MAKEFILE) uninstall
Fit/$(MAKEFILE): 
	@$(CHK_DIR_EXISTS) Fit/ || $(MKDIR) Fit/ 
	cd Fit/ && $(QMAKE) /home/pospelov/development/git/BornAgain/Fit/Fit.pro -o $(MAKEFILE)
sub-Fit-qmake_all:  FORCE
	@$(CHK_DIR_EXISTS) Fit/ || $(MKDIR) Fit/ 
	cd Fit/ && $(QMAKE) /home/pospelov/development/git/BornAgain/Fit/Fit.pro -o $(MAKEFILE)
sub-Fit: Fit/$(MAKEFILE) FORCE
	cd Fit/ && $(MAKE) -f $(MAKEFILE)
sub-Fit-make_default-ordered: Fit/$(MAKEFILE) sub-ThirdParty-RootMathMore-make_default-ordered  FORCE
	cd Fit/ && $(MAKE) -f $(MAKEFILE) 
sub-Fit-make_default: Fit/$(MAKEFILE) FORCE
	cd Fit/ && $(MAKE) -f $(MAKEFILE) 
sub-Fit-make_first-ordered: Fit/$(MAKEFILE) sub-ThirdParty-RootMathMore-make_first-ordered  FORCE
	cd Fit/ && $(MAKE) -f $(MAKEFILE) first
sub-Fit-make_first: Fit/$(MAKEFILE) FORCE
	cd Fit/ && $(MAKE) -f $(MAKEFILE) first
sub-Fit-all-ordered: Fit/$(MAKEFILE) sub-ThirdParty-RootMathMore-all-ordered  FORCE
	cd Fit/ && $(MAKE) -f $(MAKEFILE) all
sub-Fit-all: Fit/$(MAKEFILE) FORCE
	cd Fit/ && $(MAKE) -f $(MAKEFILE) all
sub-Fit-clean-ordered: Fit/$(MAKEFILE) sub-ThirdParty-RootMathMore-clean-ordered  FORCE
	cd Fit/ && $(MAKE) -f $(MAKEFILE) clean
sub-Fit-clean: Fit/$(MAKEFILE) FORCE
	cd Fit/ && $(MAKE) -f $(MAKEFILE) clean
sub-Fit-distclean-ordered: Fit/$(MAKEFILE) sub-ThirdParty-RootMathMore-distclean-ordered  FORCE
	cd Fit/ && $(MAKE) -f $(MAKEFILE) distclean
sub-Fit-distclean: Fit/$(MAKEFILE) FORCE
	cd Fit/ && $(MAKE) -f $(MAKEFILE) distclean
sub-Fit-install_subtargets-ordered: Fit/$(MAKEFILE) sub-ThirdParty-RootMathMore-install_subtargets-ordered  FORCE
	cd Fit/ && $(MAKE) -f $(MAKEFILE) install
sub-Fit-install_subtargets: Fit/$(MAKEFILE) FORCE
	cd Fit/ && $(MAKE) -f $(MAKEFILE) install
sub-Fit-uninstall_subtargets-ordered: Fit/$(MAKEFILE) sub-ThirdParty-RootMathMore-uninstall_subtargets-ordered  FORCE
	cd Fit/ && $(MAKE) -f $(MAKEFILE) uninstall
sub-Fit-uninstall_subtargets: Fit/$(MAKEFILE) FORCE
	cd Fit/ && $(MAKE) -f $(MAKEFILE) uninstall
App/$(MAKEFILE): 
	@$(CHK_DIR_EXISTS) App/ || $(MKDIR) App/ 
	cd App/ && $(QMAKE) /home/pospelov/development/git/BornAgain/App/App.pro -o $(MAKEFILE)
sub-App-qmake_all:  FORCE
	@$(CHK_DIR_EXISTS) App/ || $(MKDIR) App/ 
	cd App/ && $(QMAKE) /home/pospelov/development/git/BornAgain/App/App.pro -o $(MAKEFILE)
sub-App: App/$(MAKEFILE) FORCE
	cd App/ && $(MAKE) -f $(MAKEFILE)
sub-App-make_default-ordered: App/$(MAKEFILE) sub-Fit-make_default-ordered  FORCE
	cd App/ && $(MAKE) -f $(MAKEFILE) 
sub-App-make_default: App/$(MAKEFILE) FORCE
	cd App/ && $(MAKE) -f $(MAKEFILE) 
sub-App-make_first-ordered: App/$(MAKEFILE) sub-Fit-make_first-ordered  FORCE
	cd App/ && $(MAKE) -f $(MAKEFILE) first
sub-App-make_first: App/$(MAKEFILE) FORCE
	cd App/ && $(MAKE) -f $(MAKEFILE) first
sub-App-all-ordered: App/$(MAKEFILE) sub-Fit-all-ordered  FORCE
	cd App/ && $(MAKE) -f $(MAKEFILE) all
sub-App-all: App/$(MAKEFILE) FORCE
	cd App/ && $(MAKE) -f $(MAKEFILE) all
sub-App-clean-ordered: App/$(MAKEFILE) sub-Fit-clean-ordered  FORCE
	cd App/ && $(MAKE) -f $(MAKEFILE) clean
sub-App-clean: App/$(MAKEFILE) FORCE
	cd App/ && $(MAKE) -f $(MAKEFILE) clean
sub-App-distclean-ordered: App/$(MAKEFILE) sub-Fit-distclean-ordered  FORCE
	cd App/ && $(MAKE) -f $(MAKEFILE) distclean
sub-App-distclean: App/$(MAKEFILE) FORCE
	cd App/ && $(MAKE) -f $(MAKEFILE) distclean
sub-App-install_subtargets-ordered: App/$(MAKEFILE) sub-Fit-install_subtargets-ordered  FORCE
	cd App/ && $(MAKE) -f $(MAKEFILE) install
sub-App-install_subtargets: App/$(MAKEFILE) FORCE
	cd App/ && $(MAKE) -f $(MAKEFILE) install
sub-App-uninstall_subtargets-ordered: App/$(MAKEFILE) sub-Fit-uninstall_subtargets-ordered  FORCE
	cd App/ && $(MAKE) -f $(MAKEFILE) uninstall
sub-App-uninstall_subtargets: App/$(MAKEFILE) FORCE
	cd App/ && $(MAKE) -f $(MAKEFILE) uninstall
Tests/UnitTests/TestCore/$(MAKEFILE): 
	@$(CHK_DIR_EXISTS) Tests/UnitTests/TestCore/ || $(MKDIR) Tests/UnitTests/TestCore/ 
	cd Tests/UnitTests/TestCore/ && $(QMAKE) /home/pospelov/development/git/BornAgain/Tests/UnitTests/TestCore/TestCore.pro -o $(MAKEFILE)
sub-Tests-UnitTests-TestCore-qmake_all:  FORCE
	@$(CHK_DIR_EXISTS) Tests/UnitTests/TestCore/ || $(MKDIR) Tests/UnitTests/TestCore/ 
	cd Tests/UnitTests/TestCore/ && $(QMAKE) /home/pospelov/development/git/BornAgain/Tests/UnitTests/TestCore/TestCore.pro -o $(MAKEFILE)
sub-Tests-UnitTests-TestCore: Tests/UnitTests/TestCore/$(MAKEFILE) FORCE
	cd Tests/UnitTests/TestCore/ && $(MAKE) -f $(MAKEFILE)
sub-Tests-UnitTests-TestCore-make_default-ordered: Tests/UnitTests/TestCore/$(MAKEFILE) sub-App-make_default-ordered  FORCE
	cd Tests/UnitTests/TestCore/ && $(MAKE) -f $(MAKEFILE) 
sub-Tests-UnitTests-TestCore-make_default: Tests/UnitTests/TestCore/$(MAKEFILE) FORCE
	cd Tests/UnitTests/TestCore/ && $(MAKE) -f $(MAKEFILE) 
sub-Tests-UnitTests-TestCore-make_first-ordered: Tests/UnitTests/TestCore/$(MAKEFILE) sub-App-make_first-ordered  FORCE
	cd Tests/UnitTests/TestCore/ && $(MAKE) -f $(MAKEFILE) first
sub-Tests-UnitTests-TestCore-make_first: Tests/UnitTests/TestCore/$(MAKEFILE) FORCE
	cd Tests/UnitTests/TestCore/ && $(MAKE) -f $(MAKEFILE) first
sub-Tests-UnitTests-TestCore-all-ordered: Tests/UnitTests/TestCore/$(MAKEFILE) sub-App-all-ordered  FORCE
	cd Tests/UnitTests/TestCore/ && $(MAKE) -f $(MAKEFILE) all
sub-Tests-UnitTests-TestCore-all: Tests/UnitTests/TestCore/$(MAKEFILE) FORCE
	cd Tests/UnitTests/TestCore/ && $(MAKE) -f $(MAKEFILE) all
sub-Tests-UnitTests-TestCore-clean-ordered: Tests/UnitTests/TestCore/$(MAKEFILE) sub-App-clean-ordered  FORCE
	cd Tests/UnitTests/TestCore/ && $(MAKE) -f $(MAKEFILE) clean
sub-Tests-UnitTests-TestCore-clean: Tests/UnitTests/TestCore/$(MAKEFILE) FORCE
	cd Tests/UnitTests/TestCore/ && $(MAKE) -f $(MAKEFILE) clean
sub-Tests-UnitTests-TestCore-distclean-ordered: Tests/UnitTests/TestCore/$(MAKEFILE) sub-App-distclean-ordered  FORCE
	cd Tests/UnitTests/TestCore/ && $(MAKE) -f $(MAKEFILE) distclean
sub-Tests-UnitTests-TestCore-distclean: Tests/UnitTests/TestCore/$(MAKEFILE) FORCE
	cd Tests/UnitTests/TestCore/ && $(MAKE) -f $(MAKEFILE) distclean
sub-Tests-UnitTests-TestCore-install_subtargets-ordered: Tests/UnitTests/TestCore/$(MAKEFILE) sub-App-install_subtargets-ordered  FORCE
	cd Tests/UnitTests/TestCore/ && $(MAKE) -f $(MAKEFILE) install
sub-Tests-UnitTests-TestCore-install_subtargets: Tests/UnitTests/TestCore/$(MAKEFILE) FORCE
	cd Tests/UnitTests/TestCore/ && $(MAKE) -f $(MAKEFILE) install
sub-Tests-UnitTests-TestCore-uninstall_subtargets-ordered: Tests/UnitTests/TestCore/$(MAKEFILE) sub-App-uninstall_subtargets-ordered  FORCE
	cd Tests/UnitTests/TestCore/ && $(MAKE) -f $(MAKEFILE) uninstall
sub-Tests-UnitTests-TestCore-uninstall_subtargets: Tests/UnitTests/TestCore/$(MAKEFILE) FORCE
	cd Tests/UnitTests/TestCore/ && $(MAKE) -f $(MAKEFILE) uninstall

Makefile: BornAgain.pro  /usr/share/qt4/mkspecs/default/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		shared.pri \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf
	$(QMAKE) -o Makefile BornAgain.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_phonon.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
shared.pri:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
qmake: qmake_all FORCE
	@$(QMAKE) -o Makefile BornAgain.pro

qmake_all: sub-Core-qmake_all sub-ThirdParty-gtest-qmake_all sub-ThirdParty-RootMathMore-qmake_all sub-Fit-qmake_all sub-App-qmake_all sub-Tests-UnitTests-TestCore-qmake_all FORCE

make_default: sub-Core-make_default-ordered sub-ThirdParty-gtest-make_default-ordered sub-ThirdParty-RootMathMore-make_default-ordered sub-Fit-make_default-ordered sub-App-make_default-ordered sub-Tests-UnitTests-TestCore-make_default-ordered FORCE
make_first: sub-Core-make_first-ordered sub-ThirdParty-gtest-make_first-ordered sub-ThirdParty-RootMathMore-make_first-ordered sub-Fit-make_first-ordered sub-App-make_first-ordered sub-Tests-UnitTests-TestCore-make_first-ordered FORCE
all: sub-Core-all-ordered sub-ThirdParty-gtest-all-ordered sub-ThirdParty-RootMathMore-all-ordered sub-Fit-all-ordered sub-App-all-ordered sub-Tests-UnitTests-TestCore-all-ordered FORCE
clean: sub-Core-clean-ordered sub-ThirdParty-gtest-clean-ordered sub-ThirdParty-RootMathMore-clean-ordered sub-Fit-clean-ordered sub-App-clean-ordered sub-Tests-UnitTests-TestCore-clean-ordered FORCE
distclean: sub-Core-distclean-ordered sub-ThirdParty-gtest-distclean-ordered sub-ThirdParty-RootMathMore-distclean-ordered sub-Fit-distclean-ordered sub-App-distclean-ordered sub-Tests-UnitTests-TestCore-distclean-ordered FORCE
	-$(DEL_FILE) Makefile
install_subtargets: sub-Core-install_subtargets-ordered sub-ThirdParty-gtest-install_subtargets-ordered sub-ThirdParty-RootMathMore-install_subtargets-ordered sub-Fit-install_subtargets-ordered sub-App-install_subtargets-ordered sub-Tests-UnitTests-TestCore-install_subtargets-ordered FORCE
uninstall_subtargets: sub-Core-uninstall_subtargets-ordered sub-ThirdParty-gtest-uninstall_subtargets-ordered sub-ThirdParty-RootMathMore-uninstall_subtargets-ordered sub-Fit-uninstall_subtargets-ordered sub-App-uninstall_subtargets-ordered sub-Tests-UnitTests-TestCore-uninstall_subtargets-ordered FORCE

sub-Core-check_ordered: Core/$(MAKEFILE)
	cd Core/ && $(MAKE) -f $(MAKEFILE) check
sub-ThirdParty-gtest-check_ordered: ThirdParty/gtest/$(MAKEFILE) sub-Core-check_ordered 
	cd ThirdParty/gtest/ && $(MAKE) -f $(MAKEFILE) check
sub-ThirdParty-RootMathMore-check_ordered: ThirdParty/RootMathMore/$(MAKEFILE) sub-ThirdParty-gtest-check_ordered 
	cd ThirdParty/RootMathMore/ && $(MAKE) -f $(MAKEFILE) check
sub-Fit-check_ordered: Fit/$(MAKEFILE) sub-ThirdParty-RootMathMore-check_ordered 
	cd Fit/ && $(MAKE) -f $(MAKEFILE) check
sub-App-check_ordered: App/$(MAKEFILE) sub-Fit-check_ordered 
	cd App/ && $(MAKE) -f $(MAKEFILE) check
sub-Tests-UnitTests-TestCore-check_ordered: Tests/UnitTests/TestCore/$(MAKEFILE) sub-App-check_ordered 
	cd Tests/UnitTests/TestCore/ && $(MAKE) -f $(MAKEFILE) check
check: sub-Core-check_ordered sub-ThirdParty-gtest-check_ordered sub-ThirdParty-RootMathMore-check_ordered sub-Fit-check_ordered sub-App-check_ordered sub-Tests-UnitTests-TestCore-check_ordered

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all
install: install_subtargets  FORCE

uninstall:  uninstall_subtargets FORCE

FORCE:
