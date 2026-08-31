.syntax unified
	.align 2, 0
	.global task_poo_honey_0
	.thumb
	.thumb_func
	.type task_poo_honey_0, %function
task_poo_honey_0: @ 080CCD00
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0x0
	ldr r0, [r1, #0x00]
	str r0, [r7, #0x24]
	ldr r0, [r1, #0x04]
	str r0, [r7, #0x28]
	movs r6, #0x00
	str r6, [r7, #0x2C]
	str r6, [r7, #0x04]
	ldr r5, _080CCDD0 @ =0x09EF5AE4
	adds r0, r5, #0x0
	movs r1, #0x0E
	bl func_08003524
	strh r0, [r7, #0x20]
	adds r4, r7, #0x0
	adds r4, #0x08
	ldr r1, _080CCDD4 @ =0x09EF5B1C
	adds r0, r4, #0x0
	adds r2, r5, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x03
	movs r2, #0x01
	bl AnimStart
	adds r0, r7, #0x0
	adds r0, #0x74
	ldr r1, [r7, #0x24]
	ldr r2, [r7, #0x28]
	ldr r3, [r7, #0x2C]
	bl func_08012324
	adds r1, r7, #0x0
	adds r1, #0x34
	adds r0, r7, #0x0
	adds r0, #0x24
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r0, [r7, #0x34]
	movs r1, #0xB0
	lsls r1, r1, #0x04
	adds r0, r0, r1
	str r0, [r7, #0x34]
	ldr r0, [r7, #0x38]
	ldr r2, _080CCDD8 @ =0xFFFFF600
	adds r0, r0, r2
	str r0, [r7, #0x38]
	adds r1, r7, #0x0
	adds r1, #0x54
	adds r0, r7, #0x0
	adds r0, #0x34
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r0, [r7, #0x54]
	ldr r1, _080CCDDC @ =0xFFFFFF00
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r1, r7, #0x0
	adds r1, #0x64
	adds r0, r7, #0x0
	adds r0, #0x34
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r0, [r7, #0x64]
	movs r1, #0x80
	lsls r1, r1, #0x01
	adds r0, r0, r1
	str r0, [r7, #0x64]
	ldr r0, [r7, #0x68]
	adds r0, r0, r1
	str r0, [r7, #0x68]
	adds r4, r7, #0x0
	adds r4, #0xF4
	adds r0, r4, #0x0
	movs r1, #0x01
	bl TaskPoolInit
	adds r1, r7, #0x0
	adds r1, #0x24
	adds r0, r4, #0x0
	movs r2, #0xCC
	bl func_080CC178
	adds r0, r7, #0x0
	adds r0, #0xF0
	str r6, [r0, #0x00]
	movs r3, #0x84
	lsls r3, r3, #0x01
	adds r0, r7, r3
	strh r6, [r0, #0x00]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080CCDD0: .4byte 0x09EF5AE4
_080CCDD4: .4byte 0x09EF5B1C
_080CCDD8: .4byte 0xFFFFF600
_080CCDDC: .4byte 0xFFFFFF00
.syntax divided
