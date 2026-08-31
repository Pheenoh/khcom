.syntax unified
	.align 2, 0
	.global task_poo_owlballoon_0
	.thumb
	.thumb_func
	.type task_poo_owlballoon_0, %function
task_poo_owlballoon_0: @ 080CC960
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	adds r0, #0x24
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldr r1, [r1, #0x00]
	str r1, [r0, #0x00]
	movs r4, #0x00
	str r4, [r6, #0x2C]
	str r4, [r6, #0x30]
	ldr r5, _080CC9E8 @ =0x09EF5E38
	adds r0, r5, #0x0
	movs r1, #0x03
	bl func_08003524
	adds r1, r6, #0x0
	adds r1, #0xC8
	strh r0, [r1, #0x00]
	str r4, [r6, #0x04]
	adds r4, r6, #0x0
	adds r4, #0x0C
	ldr r1, _080CC9EC @ =0x09EF5E44
	adds r0, r4, #0x0
	adds r2, r5, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	adds r0, r4, #0x0
	bl AnimGetGfx
	str r0, [r6, #0x08]
	adds r4, #0xA4
	adds r0, r4, #0x0
	movs r1, #0x02
	bl TaskPoolInit
	ldr r1, _080CC9F0 @ =0x09EF4928
	adds r5, r6, #0x0
	adds r5, #0x24
	adds r0, r4, #0x0
	adds r2, r5, #0x0
	bl TaskCreate
	adds r1, r6, #0x0
	adds r1, #0xC4
	str r0, [r1, #0x00]
	adds r0, r6, #0x0
	adds r0, #0x34
	ldr r1, [r6, #0x24]
	ldr r2, [r6, #0x28]
	ldr r3, [r6, #0x2C]
	bl func_08012324
	adds r0, r6, #0x0
	adds r0, #0x90
	movs r1, #0x90
	lsls r1, r1, #0x02
	adds r2, r5, #0x0
	bl func_080CCB90
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CC9E8: .4byte 0x09EF5E38
_080CC9EC: .4byte 0x09EF5E44
_080CC9F0: .4byte 0x09EF4928
.syntax divided
