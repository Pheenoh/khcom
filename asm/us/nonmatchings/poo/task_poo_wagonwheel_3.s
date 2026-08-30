.syntax unified
	.align 2, 0
	.global task_poo_wagonwheel_3
	.thumb
	.thumb_func
	.type task_poo_wagonwheel_3, %function
task_poo_wagonwheel_3: @ 080D08E8
	push {r4, lr}
	adds r4, r0, #0x0
	movs r0, #0x06
	bl func_080D2D50
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D0908
	ldr r0, [r4, #0x24]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	ldr r1, [r4, #0x28]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	bl func_080D2CE0
_080D0908:
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	beq _080D091A
	ldr r0, [r4, #0x00]
	bl func_080028C0
	ldr r0, [r4, #0x04]
	bl func_08002C10
_080D091A:
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
