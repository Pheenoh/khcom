.syntax unified
	.align 2, 0
	.global task_bos_lst_fld_1
	.thumb
	.thumb_func
	.type task_bos_lst_fld_1, %function
task_bos_lst_fld_1:
	.incbin "roms/B8CJ.gba", 0x11013c, 0x588
.syntax divided
