#!/bin/sh

TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
SRCDIR=${SRCDIR:-$TOPDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

MEMEIUMD=${MEMEIUMD:-$SRCDIR/memeiumd}
MEMEIUMCLI=${MEMEIUMCLI:-$SRCDIR/memeium-cli}
MEMEIUMTX=${MEMEIUMTX:-$SRCDIR/memeium-tx}
MEMEIUMQT=${MEMEIUMQT:-$SRCDIR/qt/memeium-qt}

[ ! -x $MEMEIUMD ] && echo "$MEMEIUMD not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
MMMVER=($($MEMEIUMCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for memeiumd if --version-string is not set,
# but has different outcomes for memeium-qt and memeium-cli.
echo "[COPYRIGHT]" > footer.h2m
$MEMEIUMD --version | sed -n '1!p' >> footer.h2m

for cmd in $MEMEIUMD $MEMEIUMCLI $MEMEIUMTX $MEMEIUMQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${MMMVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${MMMVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
