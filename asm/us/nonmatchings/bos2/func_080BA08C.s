.syntax unified
	.align 2, 0
	.global func_080BA08C
	.thumb
	.thumb_func
	.type func_080BA08C, %function
func_080BA08C: @ 080BA08C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0x0
	ldr r0, [sp, #0x014]
	ldr r4, [sp, #0x018]
	ldr r5, [sp, #0x020]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r4, r4, #0x10
	lsrs r7, r4, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x08
	str r1, [r6, #0x04]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x08
	str r2, [r6, #0x08]
	lsls r3, r3, #0x10
	asrs r3, r3, #0x08
	str r3, [r6, #0x0C]
	lsls r5, r5, #0x10
	ldr r1, _080BA0E0 @ =0xFFFA0000
	adds r5, r5, r1
	lsrs r5, r5, #0x10
	cmp r5, #0x01
	bhi _080BA0D8
	adds r4, r6, #0x0
	adds r4, #0x40
	adds r2, r0, #0x0
	adds r3, r7, #0x0
	adds r0, r4, #0x0
	movs r1, #0x08
	bl func_080122AC
	ldr r1, [r6, #0x04]
	ldr r2, [r6, #0x08]
	ldr r3, [r6, #0x0C]
	adds r0, r4, #0x0
	bl func_08012324
_080BA0D8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080BA0E0: .4byte 0xFFFA0000
.syntax divided
