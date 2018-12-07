#!/usr/bin/perl -an
BEGIN { $\="\n"; $,="\t"; }
$sleep = $F[1] if ($F[2] eq "falls");
$guard = $F[3] if ($F[2] eq "Guard");

if ($F[2] eq "wakes") {
    $wake = $F[1];
    print $guard, $wake-$sleep, $sleep, $wake, $.;
}

