#!/usr/local/cpanel/3rdparty/bin/perl
#                                      Copyright 2025 WebPros International, LLC
#                                                           All rights reserved.
# copyright@cpanel.net                                         http://cpanel.net
# This code is subject to the cPanel license. Unauthorized copying is prohibited.

package ea_php_cli::cli;

BEGIN {
    delete @ENV{qw(PERL5LIB PERLLIB PERL5OPT PERL5DB PERL5SHELL PERL_DEBUG_MSTATS PERL_DESTRUCT_LEVEL)};    # Paranoid much?
    unshift @INC, '/var/cpanel/ea4';                                                                        # avoid slow use lib
}

use strict;
use warnings;

use ea_php_cli ();

my $bin = "pear";
run(@ARGV) unless caller();

sub run {
    return ea_php_cli::run( $bin, @_ );                                                                     # faster than unshift @_, "php-cgi"; goto &ea_php_cli::run; ?
}

1;
