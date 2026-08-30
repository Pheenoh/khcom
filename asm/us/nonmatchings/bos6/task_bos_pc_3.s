.syntax unified
	.align 2, 0
	.global task_bos_pc_3
	.thumb
	.thumb_func
	.type task_bos_pc_3, %function
task_bos_pc_3: @ 0810B2FC
	push {r4, lr}
	adds r4, r0, #0x0
	adds r0, #0x54
	bl func_0801B7D8
	movs r1, #0xB2
	lsls r1, r1, #0x01
	adds r0, r4, r1
	bl func_0801B7D8
	movs r1, #0x9D
	lsls r1, r1, #0x02
	adds r0, r4, r1
	bl func_08012304
	ldr r0, [r4, #0x40]
	bl func_080028C0
	ldr r0, [r4, #0x44]
	bl func_080028C0
	ldr r0, [r4, #0x48]
	bl func_080028C0
	ldr r0, [r4, #0x4C]
	bl func_08002C10
	ldr r0, [r4, #0x50]
	cmp r0, #0x00
	beq _0810B33C
	bl func_08002C10
_0810B33C:
	adds r0, r4, #0x0
	bl func_0810A4C4
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x01, 0x1C, 0x41, 0x43, 0x08, 0x1C, 0x70, 0x47
.syntax divided
