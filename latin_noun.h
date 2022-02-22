#ifndef GUARD_LATIN_NOUN_H
#define GUARD_LATIN_NOUN_H

#include<string>
#include"str_case.h"

struct Latin_noun {
private:
	// Singular declensions.
	std::string nom_sng, acc_sng, gen_sng,
		dat_sng, abl_sng,
		// Plural declensons.
		nom_plr, acc_plr, gen_plr,
		dat_plr, abl_plr,
		// Gender
		gender,
		// Noun stem
		stem;
	// Set all method, used in constructor
	void set_all(const std::string&,const std::string&,const std::string&,
		const std::string&,const std::string&,const std::string&,const std::string&,
		const std::string&,const std::string&,const std::string&,const std::string&);
	void set_all_masc(const std::string&);
	void set_all_neut(const std::string&);
	void set_all_femn(const std::string&);
	std::string str_diff(std::string::size_type, std::string::size_type, std::string::size_type);
public:
	// Constructor
	Latin_noun(const std::string&);
	// Setters
		// Singular declensions
	void set_nom_sng(const std::string&);
	void set_acc_sng(const std::string&);
	void set_gen_sng(const std::string&);
	void set_dat_sng(const std::string&);
	void set_abl_sng(const std::string&);
		// Plural declensions
	void set_nom_plr(const std::string&);
	void set_acc_plr(const std::string&);
	void set_gen_plr(const std::string&);
	void set_dat_plr(const std::string&);
	void set_abl_plr(const std::string&);
		// Noun gender
	void set_gender(const std::string&);
	// Getters
		// Singular declensions
	std::string get_nom_sng();
	std::string get_acc_sng();
	std::string get_gen_sng();
	std::string get_dat_sng();
	std::string get_abl_sng();
		// Plural declensions
	std::string get_nom_plr();
	std::string get_acc_plr();
	std::string get_gen_plr();
	std::string get_dat_plr();
	std::string get_abl_plr();
		// Noun gender
	std::string get_gender();
		// to_string()
	std::string to_string();
};

// Global variables
	// Masculine sufixes
extern std::string us, i, o, os, orum, is,
// Feminine sufixes
a, am, ae, as, arum,
// Genders
masc, femn, neut;

#endif
