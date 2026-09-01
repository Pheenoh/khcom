.syntax unified
	.align 2, 0
	.global func_08007210
	.thumb
	.thumb_func
	.type func_08007210, %function
func_08007210: @ 08007210
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	mov r12, r0
	ldr r2, _08007270 @ =0x0203406E
	ldr r1, _08007274 @ =0x04000208
	ldrh r0, [r1, #0x00]
	strh r0, [r2, #0x00]
	movs r0, #0x00
	strh r0, [r1, #0x00]
	ldr r1, _08007278 @ =0x02039830
	ldr r3, _0800727C @ =0x00000321
	adds r0, r1, r3
	ldrb r0, [r0, #0x00]
	adds r7, r1, #0x0
	cmp r0, #0x00
	bne _08007280
	movs r1, #0x00
	mov r8, r7
	ldrb r6, [r7, #0x03]
_0800723C:
	movs r2, #0x00
	adds r5, r1, #0x1
	cmp r2, r6
	bcs _08007260
	lsls r0, r1, #0x02
	mov r3, r12
	adds r1, r0, r3
	movs r4, #0x00
	mov r0, r8
	ldrb r3, [r0, #0x03]
_08007250:
	lsls r0, r2, #0x01
	adds r0, r0, r1
	strh r4, [r0, #0x00]
	adds r0, r2, #0x1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, r3
	bcc _08007250
_08007260:
	lsls r0, r5, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x03
	bls _0800723C
	movs r0, #0x01
	strb r0, [r7, #0x0C]
	b _080072F2
	.byte 0x00, 0x00
_08007270: .4byte 0x0203406E
_08007274: .4byte 0x04000208
_08007278: .4byte 0x02039830
_0800727C: .4byte 0x00000321
_08007280:
	movs r1, #0x00
	ldrb r2, [r7, #0x03]
	mov r9, r2
	movs r3, #0x90
	lsls r3, r3, #0x01
	adds r3, r3, r7
	mov r8, r3
	mov r10, r7
_08007290:
	movs r2, #0x00
	adds r5, r1, #0x1
	cmp r2, r9
	bcs _080072C4
	lsls r0, r1, #0x02
	mov r3, r12
	adds r6, r0, r3
	ldr r0, _08007308 @ =0x02039B50
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x01
	lsls r1, r1, #0x06
	adds r4, r0, r1
	mov r0, r10
	ldrb r3, [r0, #0x03]
_080072AC:
	lsls r1, r2, #0x01
	adds r1, r1, r6
	lsls r0, r2, #0x08
	adds r0, r4, r0
	add r0, r8
	ldrh r0, [r0, #0x00]
	strh r0, [r1, #0x00]
	adds r0, r2, #0x1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, r3
	bcc _080072AC
_080072C4:
	lsls r0, r5, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x03
	bls _08007290
	adds r2, r7, #0x0
	ldr r3, _0800730C @ =0x00000321
	adds r1, r2, r3
	ldrb r0, [r1, #0x00]
	subs r0, #0x01
	movs r3, #0x00
	strb r0, [r1, #0x00]
	movs r0, #0xC8
	lsls r0, r0, #0x02
	adds r2, r2, r0
	ldrb r0, [r2, #0x00]
	adds r0, #0x01
	strb r0, [r2, #0x00]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1F
	bls _080072F0
	strb r3, [r2, #0x00]
_080072F0:
	strb r3, [r7, #0x0C]
_080072F2:
	ldr r1, _08007310 @ =0x04000208
	ldr r2, _08007314 @ =0x0203406E
	ldrh r0, [r2, #0x00]
	strh r0, [r1, #0x00]
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08007308: .4byte 0x02039B50
_0800730C: .4byte 0x00000321
_08007310: .4byte 0x04000208
_08007314: .4byte 0x0203406E
.syntax divided
