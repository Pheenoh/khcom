.syntax unified
	.align 2, 0
	.global func_080783C0
	.thumb
	.thumb_func
	.type func_080783C0, %function
func_080783C0: @ 080783C0
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0x0
	ldr r1, _08078420 @ =0x09041FA0
	adds r0, r1, #0x0
	adds r0, #0xDC
	ldrh r4, [r0, #0x00]
	movs r2, #0x00
	cmp r2, r4
	bcs _08078400
	movs r3, #0x00
	ldr r7, _08078424 @ =0x09041F70
	adds r6, r1, #0x0
_080783D8:
	lsls r0, r2, #0x01
	adds r1, r0, r2
	lsls r1, r1, #0x02
	adds r1, r1, r5
	strb r3, [r1, #0x06]
	strb r3, [r1, #0x07]
	strb r3, [r1, #0x0A]
	adds r0, r0, r6
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x01
	adds r0, r0, r7
	ldrh r0, [r0, #0x00]
	str r0, [r1, #0x00]
	strh r2, [r1, #0x04]
	strb r3, [r1, #0x09]
	adds r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, r4
	bcc _080783D8
_08078400:
	lsls r0, r4, #0x01
	adds r0, r0, r4
	lsls r0, r0, #0x02
	adds r0, r0, r5
	movs r1, #0x00
	strb r1, [r0, #0x06]
	strb r1, [r0, #0x07]
	strb r1, [r0, #0x0A]
	ldr r1, _08078428 @ =0x0000FFFE
	str r1, [r0, #0x00]
	movs r1, #0x00
	strh r4, [r0, #0x04]
	strb r1, [r0, #0x09]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08078420: .4byte 0x09041FA0
_08078424: .4byte 0x09041F70
_08078428: .4byte 0x0000FFFE
.syntax divided
