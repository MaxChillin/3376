#!/usr/bin/perl -w

use strict;
use warnings;
use diagnostics;
use feature 'say';
use feature "switch";
use Cwd;

use v5.16;

my $dir= getcwd;
my @c_files;
my @pl_files;
my @txt_files;
my @other_files;

my $c_count= 0;
my $pl_count= 0;
my $txt_count= 0;
my $other_count= 0;

my $c_byte_total;
my $pl_byte_total;
my $txt_byte_total;
my $other_byte_total;

opendir DIR, $dir or die "cannot open dir $dir: $!";
my @file= readdir DIR;
closedir DIR;

foreach (@file){
	# This is to identify the directory files
	if ((substr `stat --format "%F" $_`, 0, 3) eq "dir"){
		next;
	}
	my $fileName = $_;
	if ((substr $fileName, -2) eq ".c"){
		$c_byte_total+= ((split ' ', `ls -l $fileName | cut -c 21-25`)[0]);
		$c_count+= 1;
		push @c_files, $fileName;
	}elsif((substr $fileName, -3) eq ".pl"){
		$pl_byte_total+= ((split ' ', `ls -l $fileName | cut -c 21-25`)[0]);
		$pl_count+= 1;
		push @pl_files, $fileName;
	}elsif((substr $fileName, -4) eq ".txt"){
		$txt_byte_total+= ((split ' ', `ls -l $fileName | cut -c 21-25`)[0]);
		$txt_count+= 1;
		push @txt_files, $fileName;
	}else{
		$other_byte_total+= ((split ' ', `ls -l $fileName | cut -c 21-25`)[0]);
		$other_count+= 1;
		push @other_files, $fileName;
	}
	
}# end of foreach loop

my %count = (
	"C_Files"=>$c_count,
	"Perl_Files"=>$pl_count,
	"Text_Files"=>$txt_count,
	"Other_Files"=>$other_count
);
my %bytes = (
	"C_Bytes"=>$c_byte_total,
	"Perl_Bytes"=>$pl_byte_total,
	"Text_Bytes"=>$txt_byte_total,
	"Other_Bytes"=>$other_byte_total,
);


printf("\nFile Extension %10s\n", "Count");
printf("-------------- %11s\n", "-------");
printf("%-5s %17s\n", ".c", $count{C_Files});
printf("%-5s %17s\n", ".pl", $count{Perl_Files});
printf("%-5s %17s\n", ".txt", $count{Text_Files});
printf("%-5s %17s\n", "*", $count{Other_Files});
printf("--------------------------\n");
printf("%-5s %17s\n", "Total", ($c_count + $pl_count + $txt_count + $other_count));

printf("\nFile Extension %10s\n", "Bytes");
printf("-------------- %11s\n", "-------");
printf("%-5s %18s\n", ".c", $bytes{C_Bytes});
printf("%-5s %18s\n", ".pl", $bytes{Perl_Bytes});
printf("%-5s %18s\n", ".txt", $bytes{Text_Bytes});
printf("%-5s %18s\n", "*", $bytes{Other_Bytes});
printf("--------------------------\n");
printf("%-5s %18s\n", "Total", ($c_byte_total + $pl_byte_total + $txt_byte_total + $other_byte_total));
