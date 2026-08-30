.syntax unified
	.align 2, 0
	.global func_08078330
	.thumb
	.thumb_func
	.type func_08078330, %function
func_08078330: @ 08078330
	push {r4, r5, r6, r7, lr}
	add sp, #-0x004
	adds r7, r0, #0x0
	adds r5, r1, #0x0
	adds r0, r5, #0x0
	bl func_080858B8
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r0, r4, #0x01
	bl func_08000918
	adds r6, r0, #0x0
	mov r1, sp
	movs r0, #0x00
	strh r0, [r1, #0x00]
	movs r2, #0x80
	lsls r2, r2, #0x11
	orrs r2, r4
	mov r0, sp
	adds r1, r6, #0x0
	bl func_08117FE8
	adds r0, r5, #0x0
	adds r1, r6, #0x0
	bl func_08085A58
	movs r2, #0x00
	cmp r2, r4
	bcs _08078390
	movs r3, #0x00
_0807836E:
	lsls r1, r2, #0x01
	adds r0, r1, r2
	lsls r0, r0, #0x02
	adds r0, r0, r7
	strb r3, [r0, #0x06]
	strb r3, [r0, #0x07]
	strb r3, [r0, #0x0A]
	adds r1, r1, r6
	ldrh r1, [r1, #0x00]
	str r1, [r0, #0x00]
	strh r2, [r0, #0x04]
	strb r3, [r0, #0x09]
	adds r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, r4
	bcc _0807836E
_08078390:
	cmp r5, #0x00
	bne _080783AC
	lsls r0, r4, #0x01
	adds r0, r0, r4
	lsls r0, r0, #0x02
	adds r0, r0, r7
	strb r5, [r0, #0x06]
	strb r5, [r0, #0x07]
	strb r5, [r0, #0x0A]
	ldr r1, _080783BC @ =0x0000FFFE
	str r1, [r0, #0x00]
	movs r1, #0x00
	strh r4, [r0, #0x04]
	strb r1, [r0, #0x09]
_080783AC:
	adds r0, r6, #0x0
	bl func_080009C4
	add sp, #0x004
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080783BC: .4byte 0x0000FFFE
.syntax divided
