#pragma once

#include "Emu/GameInfo.h"

class ElfLoader //TODO
{
	/*
	struct PsfHeader
	{
		u32		magic; //46535000 (PSF)
		u64		unknown_0[28];
		u32		list[34];
		u32		app_ver[3];
		u32		attribute;
		u32		license[129];
		u32		comm_id[4];
		u32		unknown_1;
		u64		plevel;
		u32		unknown_2[3];
		u32		name[31];
		u64		reg[2];
		u32		ver[3];
	};
	*/

	struct PsfHeader
	{
		u32		comm_id[4];
		u32		unknown_1;
		u64		plevel;
		u32		unknown_2[3];
		u32		name[31];
		u64		reg[2];
		u32		ver[3];
	};

	struct SelfHeader
	{
		u32 magic;
		u32 headerVer;
		u16 flags;
		u16 type;
		u32 meta;
		u64 headerSize;
		u64 encryptedSize;
		u64 unknown;
		u64 AppInfo;
		u64 elf;
		u64 phdr;
		u64 shdr;
		u64 phdrOffsets;
		u64 sceversion;
		u64 digest;
		u64 digestSize;
		/*
		u32		magic;
		u32		version;
		u16		attribute;
		u16		category;
		u32		metadataInfoOffset;
		u64		fileOffset;
		u64		fileSize;
		u64		id;
		u64		programInfoOffset;
		u64		elfHeaderOffset;
		u64		elfProgramHeadersOffset;
		u64		elfSectionHeadersOffset;
		u64		sInfoOffset;
		u64		versionInfoOffset;
		u64		controlInfoOffset;
		u64		controlInfoSize;
		u64		app;
		*/
	};

	struct Elf32_Ehdr
	{
		u8		e_magic[16];
		u16		e_type;
		u16		e_machine;
		u32		e_version;
		u32		e_entry;
		u32		e_phoff;
		u32		e_shoff;
		u32		e_flags;
		u16		e_ehsize;
		u16		e_phentsize;
		u16		e_phnum;
		u16		e_shentsize;
		u16		e_shnum;
		u16		e_shstrndx;
	};

	struct Elf64_Ehdr
	{
		u8 Magic[16];
		u32 unknown[3];
		/*
		u16 Data;
		u16 CurVersion;
		u16 OS_ABI;
		u32 unknown_0;
		u8 ABI_Version;
		u32 Type;
		u32 Machine;
		u32 Version;
		*/
		u32 entry;
		u64 phoff;
		u64 shoff;
		u32 flags;
		u16 ehsize;
		u16 phentsize;
		u16 phnum;
		u16 shentsize;
		u16 shnum;
		u16 shstrndx;
	};

	struct Elf64_Shdr
	{
		u32     sh_name; 
		u32     sh_type;
		u64     sh_flags;
		u64     sh_addr;
		u64     sh_offset;
		u64     sh_size;
		u32     sh_link;
		u32     sh_info;
		u64     sh_addralign;
		u64     sh_entsize;
	};

	struct Elf64_Phdr
	{
		u32		p_type;
		u32		p_flags;
		u64		p_offset;
		u64		p_vaddr;
		u64		p_paddr;
		u64		p_filesz;
		u64		p_memsz;
		u64		p_align;
	};

	wxString m_elf_fpatch;

public:
	uint elf_size;

	ElfLoader()
	{
		elf_size = 0;
	}

	void SetElf(wxString elf_full_patch);
	void LoadElf();
	void LoadSelf();

private:
	void LoadElf32(Elf32_Ehdr& header, wxFile& elf);
	void LoadElf64(Elf64_Ehdr& header, wxFile& elf);

	void LoadPsf();
};

extern ElfLoader elf_loader;