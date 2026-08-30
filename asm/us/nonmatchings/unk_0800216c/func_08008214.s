.syntax unified
	.align 2, 0
	.global func_08008214
	.thumb
	.thumb_func
	.type func_08008214, %function
func_08008214: @ 08008214
	push {r4, r5, lr}
	add sp, #-0x004
	adds r4, r0, #0x0
	mov r1, sp
	ldr r0, _0800826C @ =0x04000006
	ldrh r0, [r0, #0x00]
	strh r0, [r1, #0x00]
	mov r5, sp
	mov r0, sp
	ldrh r0, [r0, #0x00]
	adds r0, #0x01
	movs r1, #0xE4
	bl func_0811D684
	strh r0, [r5, #0x00]
	ldr r0, _08008270 @ =0x02039B70
	lsls r4, r4, #0x02
	adds r4, r4, r0
	ldrb r0, [r4, #0x02]
	cmp r0, #0x01
	bne _08008264
	ldr r3, _08008274 @ =0x04000010
	ldr r2, _08008278 @ =0x08121400
	mov r0, sp
	ldrh r1, [r0, #0x00]
	ldr r0, _0800827C @ =0x03007480
	ldr r0, [r0, #0x00]
	adds r1, r1, r0
	ldrb r0, [r4, #0x01]
	muls r0, r1
	movs r1, #0xFF
	ands r0, r1
	lsls r0, r0, #0x01
	adds r0, r0, r2
	movs r2, #0x00
	ldsh r1, [r0, r2]
	ldrb r0, [r4, #0x00]
	muls r0, r1
	asrs r0, r0, #0x08
	strh r0, [r3, #0x00]
_08008264:
	add sp, #0x004
	pop {r4, r5}
	pop {r0}
	bx r0
_0800826C: .4byte 0x04000006
_08008270: .4byte 0x02039B70
_08008274: .4byte 0x04000010
_08008278: .4byte 0x08121400
_0800827C: .4byte 0x03007480
.syntax divided
