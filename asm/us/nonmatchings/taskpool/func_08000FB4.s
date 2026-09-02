.syntax unified
	.align 2, 0
	.global func_08000FB4
	.thumb
	.thumb_func
	.type func_08000FB4, %function
func_08000FB4: @ 08000FB4
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	adds r6, r1, #0x0
	bl _08006338
	ldr r1, _08001000 @ =0x0300749E
	strh r0, [r1, #0x00]
	bl VTransReset
	bl func_08004D74
	bl func_08001F98
	bl FadeReset
	bl func_08006404
	ldr r5, _08001004 @ =0x03007488
	str r4, [r5, #0x00]
	ldr r1, [r4, #0x04]
	cmp r1, #0x00
	beq _08000FE6
	adds r0, r6, #0x0
	bl _call_via_r1
_08000FE6:
	ldr r1, _08001008 @ =0x0300748C
	ldr r0, [r5, #0x00]
	ldr r0, [r0, #0x08]
	str r0, [r1, #0x00]
	ldr r2, _0800100C @ =0x0300749C
	ldrb r0, [r2, #0x00]
	movs r1, #0x08
	orrs r0, r1
	strb r0, [r2, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08001000: .4byte 0x0300749E
_08001004: .4byte 0x03007488
_08001008: .4byte 0x0300748C
_0800100C: .4byte 0x0300749C
.syntax divided
