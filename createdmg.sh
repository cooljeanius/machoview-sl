#!/bin/bash
# Create DMG Installer.

set -ex

buildPlist="build/MachOView.app/Contents/Info.plist"
CFBuildNumber=$(/usr/libexec/PlistBuddy -c "Print CFBuildNumber" ${buildPlist})
CFBundleShortVersionString=$(/usr/libexec/PlistBuddy -c "Print CFBundleShortVersionString" ${buildPlist})
cp -fv README* build
hdiutil create -fs HFS+ -volname "MachOView" -srcfolder build "MachOView "${CFBundleShortVersionString}.${CFBuildNumber}".dmg"
