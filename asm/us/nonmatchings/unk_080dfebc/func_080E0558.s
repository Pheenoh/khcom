.syntax unified
	.align 2, 0
	.global func_080E0558
	.thumb
	.thumb_func
	.type func_080E0558, %function
func_080E0558: @ 080E0558
	push {r4, r5, r6, lr}
	ldr r5, _080E05DC @ =0x02039BA0
	ldr r2, [r5, #0x00]
	movs r4, #0x00
	str r4, [r2, #0x00]
	str r4, [r2, #0x04]
	str r4, [r2, #0x08]
	str r4, [r2, #0x0C]
	movs r6, #0x00
	movs r0, #0x20
	strh r0, [r2, #0x10]
	strh r0, [r2, #0x12]
	str r4, [r2, #0x68]
	adds r1, r2, #0x0
	adds r1, #0x6C
	movs r0, #0x3C
	strh r0, [r1, #0x00]
	str r4, [r2, #0x70]
	adds r0, r2, #0x0
	adds r0, #0x74
	strh r4, [r0, #0x00]
	adds r0, #0x04
	movs r1, #0x32
	bl func_08000E64
	ldr r0, [r5, #0x00]
	adds r0, #0x8C
	movs r1, #0x01
	bl func_08000E64
	ldr r0, [r5, #0x00]
	adds r0, #0x58
	bl func_08000BA4
	ldr r0, [r5, #0x00]
	adds r0, #0xA0
	movs r1, #0x19
	bl func_08000E64
	ldr r0, [r5, #0x00]
	adds r0, #0xC8
	movs r1, #0x01
	bl func_08000E64
	ldr r0, [r5, #0x00]
	adds r0, #0xB4
	movs r1, #0x08
	bl func_08000E64
	ldr r1, _080E05E0 @ =0x0203C7AC
	ldr r0, [r1, #0x00]
	str r4, [r0, #0x00]
	strb r6, [r0, #0x18]
	ldr r0, [r1, #0x00]
	str r4, [r0, #0x1C]
	adds r0, #0x20
	strb r6, [r0, #0x00]
	ldr r0, [r1, #0x00]
	adds r0, #0x30
	movs r1, #0x01
	bl func_08000E64
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080E05DC: .4byte 0x02039BA0
_080E05E0: .4byte 0x0203C7AC
.syntax divided
