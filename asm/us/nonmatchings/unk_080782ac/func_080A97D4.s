.syntax unified
	.align 2, 0
	.global func_080A97D4
	.thumb
	.thumb_func
	.type func_080A97D4, %function
func_080A97D4: @ 080A97D4
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x014
	adds r6, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r10, r1
	movs r3, #0x00
	mov r9, r3
	mov r8, r3
	movs r1, #0xDC
	lsls r1, r1, #0x03
	adds r0, r6, r1
	ldrh r0, [r0, #0x00]
	cmp r3, r0
	bcs _080A98DC
	mov r5, sp
_080A97FC:
	mov r2, r10
	cmp r2, #0x05
	bne _080A9844
	ldr r1, _080A983C @ =0x000004CC
	adds r0, r6, r1
	ldr r1, [r0, #0x00]
	mov r2, r8
	lsls r0, r2, #0x05
	adds r1, r0, r1
	ldrh r0, [r1, #0x14]
	cmp r0, #0x4D
	bhi _080A98AE
	ldr r2, _080A9840 @ =0x0000063C
	adds r0, r6, r2
	str r0, [sp, #0x000]
	ldrh r0, [r1, #0x14]
	str r3, [sp, #0x010]
	bl func_080A993C
	strh r0, [r5, #0x04]
	ldr r3, [sp, #0x010]
	lsls r4, r3, #0x18
	asrs r4, r4, #0x18
	strh r4, [r5, #0x06]
	mov r1, r9
	lsls r0, r1, #0x18
	asrs r0, r0, #0x18
	strh r0, [r5, #0x08]
	movs r0, #0x01
	strb r0, [r5, #0x0A]
	movs r2, #0x00
	b _080A989A
_080A983C: .4byte 0x000004CC
_080A9840: .4byte 0x0000063C
_080A9844:
	ldr r2, _080A9920 @ =0x0000063C
	adds r0, r6, r2
	str r0, [sp, #0x000]
	ldr r0, _080A9924 @ =0x000004CC
	adds r7, r6, r0
	ldr r0, [r7, #0x00]
	mov r1, r8
	lsls r4, r1, #0x05
	adds r0, r4, r0
	ldrh r0, [r0, #0x14]
	str r3, [sp, #0x010]
	bl func_080A993C
	movs r2, #0x00
	mov r12, r2
	strh r0, [r5, #0x04]
	ldr r2, _080A9928 @ =0x08F70AB0
	ldrh r1, [r5, #0x04]
	movs r0, #0x34
	muls r0, r1
	adds r0, r0, r2
	adds r0, #0x2A
	ldrb r1, [r0, #0x00]
	mov r0, r10
	subs r0, #0x01
	ldr r3, [sp, #0x010]
	cmp r1, r0
	bne _080A98AE
	ldr r0, [r7, #0x00]
	adds r0, r4, r0
	ldrh r0, [r0, #0x14]
	cmp r0, #0x4D
	bhi _080A98AE
	lsls r4, r3, #0x18
	asrs r4, r4, #0x18
	strh r4, [r5, #0x06]
	mov r1, r9
	lsls r0, r1, #0x18
	asrs r0, r0, #0x18
	strh r0, [r5, #0x08]
	movs r0, #0x01
	strb r0, [r5, #0x0A]
	mov r2, r12
_080A989A:
	str r2, [sp, #0x00C]
	ldr r1, _080A992C @ =0x00000614
	adds r0, r6, r1
	ldr r1, _080A9930 @ =0x09EE4B28
	mov r2, sp
	bl func_08000E14
	adds r4, #0x01
	lsls r4, r4, #0x18
	lsrs r3, r4, #0x18
_080A98AE:
	lsls r0, r3, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x02
	ble _080A98C6
	movs r3, #0x00
	mov r2, r9
	lsls r0, r2, #0x18
	movs r1, #0x80
	lsls r1, r1, #0x11
	adds r0, r0, r1
	lsrs r0, r0, #0x18
	mov r9, r0
_080A98C6:
	mov r0, r8
	adds r0, #0x01
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	movs r2, #0xDC
	lsls r2, r2, #0x03
	adds r0, r6, r2
	ldrh r0, [r0, #0x00]
	cmp r8, r0
	bcc _080A97FC
_080A98DC:
	ldr r0, _080A9934 @ =0x0000069C
	adds r1, r6, r0
	movs r0, #0xA0
	lsls r0, r0, #0x08
	str r0, [r1, #0x00]
	movs r2, #0xD4
	lsls r2, r2, #0x03
	adds r1, r6, r2
	movs r0, #0xA0
	lsls r0, r0, #0x06
	str r0, [r1, #0x00]
	ldr r0, _080A9938 @ =0x000006EC
	adds r1, r6, r0
	movs r0, #0x04
	strh r0, [r1, #0x00]
	mov r1, r9
	lsls r0, r1, #0x18
	asrs r0, r0, #0x18
	lsls r2, r0, #0x01
	adds r2, r2, r0
	lsls r1, r3, #0x18
	asrs r1, r1, #0x18
	adds r1, r1, r2
	adds r0, r6, #0x0
	bl func_080AAEEC
	add sp, #0x014
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_080A9920: .4byte 0x0000063C
_080A9924: .4byte 0x000004CC
_080A9928: .4byte 0x08F70AB0
_080A992C: .4byte 0x00000614
_080A9930: .4byte 0x09EE4B28
_080A9934: .4byte 0x0000069C
_080A9938: .4byte 0x000006EC
.syntax divided
