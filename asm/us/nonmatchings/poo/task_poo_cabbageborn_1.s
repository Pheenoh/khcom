.syntax unified
	.align 2, 0
	.global task_poo_cabbageborn_1
	.thumb
	.thumb_func
	.type task_poo_cabbageborn_1, %function
task_poo_cabbageborn_1: @ 080D16A4
	push {r4, lr}
	adds r4, r0, #0x0
	bl func_080D1650
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D16C6
	ldrh r0, [r4, #0x16]
	cmp r0, #0x00
	bne _080D16CC
	ldr r1, _080D16E0 @ =0x09EF4C10
	adds r0, r4, #0x0
	movs r2, #0x00
	bl func_08000E14
	movs r0, #0x28
	strh r0, [r4, #0x16]
_080D16C6:
	ldrh r0, [r4, #0x16]
	cmp r0, #0x00
	beq _080D16D0
_080D16CC:
	subs r0, #0x01
	strh r0, [r4, #0x16]
_080D16D0:
	adds r0, r4, #0x0
	bl func_08000EA4
	movs r0, #0x01
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080D16E0: .4byte 0x09EF4C10
.syntax divided
