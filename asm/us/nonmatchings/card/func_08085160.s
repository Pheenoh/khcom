.syntax unified
	.align 2, 0
	.global func_08085160
	.thumb
	.thumb_func
	.type func_08085160, %function
func_08085160: @ 08085160
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	movs r5, #0x00
	ldr r0, _080851D8 @ =0x02039DE0
	mov r12, r0
	movs r6, #0x00
	ldr r1, _080851DC @ =0x0000FFFF
	mov r8, r1
_08085174:
	movs r2, #0x00
	lsls r3, r5, #0x03
	adds r7, r5, #0x1
	mov r9, r7
	subs r0, r3, r5
	lsls r4, r0, #0x05
_08085180:
	lsls r0, r2, #0x01
	adds r0, r0, r4
	add r0, r12
	ldrh r1, [r0, #0x00]
	mov r7, r8
	orrs r1, r7
	strh r1, [r0, #0x00]
	adds r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0x62
	bls _08085180
	movs r2, #0x00
	subs r0, r3, r5
	lsls r1, r0, #0x05
	ldr r4, _080851E0 @ =0x02039EA6
_080851A0:
	adds r0, r2, r1
	adds r0, r0, r4
	strb r6, [r0, #0x00]
	adds r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0x13
	bls _080851A0
	subs r0, r3, r5
	lsls r0, r0, #0x05
	add r0, r12
	adds r1, r0, #0x0
	adds r1, #0xDA
	strh r6, [r1, #0x00]
	adds r0, #0xDC
	strh r6, [r0, #0x00]
	mov r1, r9
	lsls r0, r1, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0x02
	bls _08085174
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080851D8: .4byte 0x02039DE0
_080851DC: .4byte 0x0000FFFF
_080851E0: .4byte 0x02039EA6
.syntax divided
