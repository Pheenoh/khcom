.syntax unified
	.align 2, 0
	.global task_bos_pc_fld_3
	.thumb
	.thumb_func
	.type task_bos_pc_fld_3, %function
task_bos_pc_fld_3: @ 0810B7AC
	push {r4, lr}
	adds r4, r0, #0x0
	bl func_0810B51C
	adds r0, r4, #0x0
	adds r0, #0x10
	bl func_08012304
	ldr r0, [r4, #0x08]
	cmp r0, #0x00
	beq _0810B7C6
	bl func_080028C0
_0810B7C6:
	ldr r0, [r4, #0x0C]
	cmp r0, #0x00
	beq _0810B7D0
	bl func_08002C10
_0810B7D0:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00, 0x01, 0x1C, 0x41, 0x43, 0x08, 0x1C, 0x70, 0x47, 0x01, 0x1C, 0x41, 0x43, 0x08, 0x1C
	.byte 0x70, 0x47
.syntax divided
