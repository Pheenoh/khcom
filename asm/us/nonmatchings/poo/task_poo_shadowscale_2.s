.syntax unified
	.align 2, 0
	.global task_poo_shadowscale_2
	.thumb
	.thumb_func
	.type task_poo_shadowscale_2, %function
task_poo_shadowscale_2: @ 080CC0EC
	push {r4, r5, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	ldr r0, [r4, #0x10]
	ldr r0, [r0, #0x08]
	cmp r0, #0x00
	blt _080CC0FE
	ldr r2, [r4, #0x2C]
	b _080CC10C
_080CC0FE:
	adds r0, #0x7F
	asrs r0, r0, #0x07
	ldr r1, [r4, #0x2C]
	adds r2, r1, r0
	cmp r2, #0x18
	bgt _080CC10C
	movs r2, #0x19
_080CC10C:
	movs r0, #0x00
	adds r1, r2, #0x0
	movs r3, #0x00
	bl func_08002CB4
	adds r5, r0, #0x0
	ldr r0, [r4, #0x00]
	asrs r0, r0, #0x08
	ldr r1, _080CC154 @ =0x0203C40C
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	ldr r1, [r4, #0x04]
	asrs r1, r1, #0x08
	ldr r2, _080CC158 @ =0x0203C3F8
	ldrh r2, [r2, #0x00]
	subs r1, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r4, #0x30]
	ldr r3, [r4, #0x08]
	ldr r4, [r4, #0x0C]
	str r4, [sp, #0x000]
	str r5, [sp, #0x004]
	movs r4, #0x80
	lsls r4, r4, #0x04
	str r4, [sp, #0x008]
	ldr r4, _080CC15C @ =0x0000FFF0
	str r4, [sp, #0x00C]
	bl func_080023E0
	add sp, #0x010
	pop {r4, r5}
	pop {r0}
	bx r0
_080CC154: .4byte 0x0203C40C
_080CC158: .4byte 0x0203C3F8
_080CC15C: .4byte 0x0000FFF0
.syntax divided
