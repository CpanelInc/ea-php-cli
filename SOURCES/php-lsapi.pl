#!/usr/local/cpanel/3rdparty/bin/perl
# cpanel - php-lsapi                               Copyright 2018 cPanel, L.L.C.
#                                                           All rights Reserved.
# copyright@cpanel.net                                         http://cpanel.net
# This code is subject to the cPanel license. Unauthorized copying is prohibited

package ea_php_cli::lsapi;

use strict;
use warnings;

use lib '/var/cpanel/ea4/ea-php-cli';
use ea_php_cli;

my $bin = "lsphp";
run(@ARGV) unless caller();

sub run {
    return ea_php_cli::run( $bin, @_ );    # faster than unshift @_, "php-cgi"; goto &ea_php_cli::run; ?
}

1;
