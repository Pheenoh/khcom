.syntax unified
	.align 2, 0
	.global func_080122AC
	.thumb
	.thumb_func
	.type func_080122AC, %function
func_080122AC: @ 080122AC
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	adds r4, r1, #0x0
	lsls r2, r2, #0x10
	lsls r3, r3, #0x10
	movs r1, #0x00
	str r1, [r5, #0x34]
	adds r0, #0x2C
	strb r1, [r0, #0x00]
	strh r1, [r5, #0x2E]
	strh r1, [r5, #0x30]
	lsrs r2, r2, #0x08
	str r2, [r5, #0x10]
	lsrs r3, r3, #0x08
	str r3, [r5, #0x14]
	str r4, [r5, #0x00]
	str r5, [r5, #0x54]
	str r1, [r5, #0x58]
	adds r0, r4, #0x0
	bl _08012218
	adds r6, r0, #0x0
	cmp r4, #0x07
	bhi _080122E8
	cmp r4, #0x06
	bcc _080122E8
	ldrh r0, [r5, #0x30]
	movs r1, #0x01
	orrs r0, r1
	strh r0, [r5, #0x30]
_080122E8:
	adds r4, r5, #0x0
	adds r4, #0x18
	adds r0, r4, #0x0
	adds r1, r6, #0x0
	adds r2, r5, #0x0
	bl func_08000D20
	adds r0, r4, #0x0
	adds r1, r6, #0x0
	bl func_08000D28
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.syntax divided
