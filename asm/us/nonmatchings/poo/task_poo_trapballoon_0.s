.syntax unified
	.align 2, 0
	.global task_poo_trapballoon_0
	.thumb
	.thumb_func
	.type task_poo_trapballoon_0, %function
task_poo_trapballoon_0: @ 080CC5F0
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0x0
	adds r0, #0x24
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldr r1, [r1, #0x00]
	str r1, [r0, #0x00]
	movs r5, #0x00
	str r5, [r7, #0x2C]
	str r5, [r7, #0x30]
	ldr r6, _080CC678 @ =0x09EF5AD0
	adds r0, r6, #0x0
	movs r1, #0x04
	bl func_08003524
	adds r1, r7, #0x0
	adds r1, #0xCC
	strh r0, [r1, #0x00]
	str r5, [r7, #0x04]
	adds r4, r7, #0x0
	adds r4, #0x0C
	ldr r1, _080CC67C @ =0x09EF5AE0
	adds r0, r4, #0x0
	adds r2, r6, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
	adds r0, r4, #0x0
	bl func_08005AFC
	str r0, [r7, #0x08]
	adds r4, #0xA4
	adds r0, r4, #0x0
	movs r1, #0x03
	bl func_08000E64
	ldr r1, _080CC680 @ =0x09EF4928
	adds r2, r7, #0x0
	adds r2, #0x24
	adds r0, r4, #0x0
	bl func_08000E14
	adds r1, r7, #0x0
	adds r1, #0xC4
	str r0, [r1, #0x00]
	adds r0, r7, #0x0
	adds r0, #0xC8
	str r5, [r0, #0x00]
	bl func_080065A4
	adds r1, r7, #0x0
	adds r1, #0xCE
	strh r0, [r1, #0x00]
	adds r0, r7, #0x0
	adds r0, #0x34
	ldr r1, [r7, #0x24]
	ldr r2, [r7, #0x28]
	ldr r3, [r7, #0x2C]
	bl func_08012324
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CC678: .4byte 0x09EF5AD0
_080CC67C: .4byte 0x09EF5AE0
_080CC680: .4byte 0x09EF4928
.syntax divided
