.syntax unified
	.align 2, 0
	.global task_bos_lst_snp_3
	.thumb
	.thumb_func
	.type task_bos_lst_snp_3, %function
task_bos_lst_snp_3:
	.incbin "roms/B8CJ.gba", 0x112618, 0x21bc
.syntax divided
