.syntax unified
	.align 2, 0
	.global func_080B2FEC
	.thumb
	.thumb_func
	.type func_080B2FEC, %function
func_080B2FEC: @ 080B2FEC
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x004
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0x00
	bne _080B3002
	b _080B3180
_080B3002:
	lsrs r0, r1, #0x0C
	mov r10, r0
	ldr r0, _080B30C4 @ =0x00000FFF
	ands r0, r1
	subs r0, #0x01
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x000]
	movs r0, #0x80
	lsls r0, r0, #0x04
	ldr r1, [sp, #0x000]
	cmp r1, r0
	bne _080B30D8
	ldr r2, _080B30C8 @ =0x02034B4C
	mov r8, r2
	ldr r0, [r2, #0x00]
	adds r0, #0xA5
	add r0, r10
	movs r1, #0x00
	strb r1, [r0, #0x00]
	ldr r0, [r2, #0x00]
	mov r3, r10
	lsls r6, r3, #0x02
	movs r1, #0x80
	lsls r1, r1, #0x01
	mov r9, r1
	add r0, r9
	adds r0, r0, r6
	ldr r0, [r0, #0x00]
	bl ReleaseObjTiles
	mov r2, r8
	ldr r0, [r2, #0x00]
	movs r4, #0x94
	lsls r4, r4, #0x01
	adds r0, r0, r4
	adds r0, r0, r6
	ldr r0, [r0, #0x00]
	bl ReleaseObjPalette
	ldr r5, _080B30CC @ =0x08F70AB0
	ldr r0, [r5, #0x14]
	movs r1, #0x80
	lsls r1, r1, #0x02
	bl LoadObjTiles
	mov r3, r8
	ldr r1, [r3, #0x00]
	add r1, r9
	adds r1, r1, r6
	str r0, [r1, #0x00]
	ldr r0, [r5, #0x18]
	movs r1, #0x20
	bl LoadObjPalette
	mov r1, r8
	ldr r2, [r1, #0x00]
	adds r4, r2, r4
	adds r4, r4, r6
	str r0, [r4, #0x00]
	movs r3, #0xA8
	lsls r3, r3, #0x01
	adds r0, r2, r3
	adds r0, r0, r6
	ldr r1, [r5, #0x10]
	str r1, [r0, #0x00]
	movs r1, #0xC0
	lsls r1, r1, #0x01
	adds r0, r2, r1
	adds r0, r0, r6
	ldr r1, _080B30D0 @ =0x09EE981C
	ldr r1, [r1, #0x00]
	str r1, [r0, #0x00]
	ldr r1, _080B30D4 @ =0x0203AB20
	mov r3, r10
	lsls r0, r3, #0x01
	adds r0, r0, r1
	mov r1, sp
	ldrh r1, [r1, #0x00]
	strh r1, [r0, #0x00]
	movs r3, #0xD8
	lsls r3, r3, #0x02
	adds r0, r2, r3
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x01
	bne _080B3180
	adds r0, r2, #0x0
	adds r0, #0x76
	movs r1, #0x00
	ldsh r0, [r0, r1]
	cmp r10, r0
	bne _080B3180
	bl func_080B3A48
	b _080B3180
_080B30C4: .4byte 0x00000FFF
_080B30C8: .4byte 0x02034B4C
_080B30CC: .4byte 0x08F70AB0
_080B30D0: .4byte 0x09EE981C
_080B30D4: .4byte 0x0203AB20
_080B30D8:
	ldr r2, _080B3190 @ =0x02034B4C
	mov r8, r2
	ldr r0, [r2, #0x00]
	adds r0, #0xA5
	add r0, r10
	movs r1, #0x01
	strb r1, [r0, #0x00]
	ldr r0, [r2, #0x00]
	mov r3, r10
	lsls r6, r3, #0x02
	adds r1, #0xFF
	mov r9, r1
	add r0, r9
	adds r0, r0, r6
	ldr r0, [r0, #0x00]
	bl ReleaseObjTiles
	mov r2, r8
	ldr r0, [r2, #0x00]
	movs r5, #0x94
	lsls r5, r5, #0x01
	adds r0, r0, r5
	adds r0, r0, r6
	ldr r0, [r0, #0x00]
	bl ReleaseObjPalette
	ldr r7, _080B3194 @ =0x08F70AB0
	movs r0, #0x34
	ldr r3, [sp, #0x000]
	adds r4, r3, #0x0
	muls r4, r0
	adds r0, r7, #0x0
	adds r0, #0x14
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	movs r1, #0x80
	lsls r1, r1, #0x02
	bl LoadObjTiles
	mov r2, r8
	ldr r1, [r2, #0x00]
	add r1, r9
	adds r1, r1, r6
	str r0, [r1, #0x00]
	adds r0, r7, #0x0
	adds r0, #0x18
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	movs r1, #0x20
	bl LoadObjPalette
	mov r3, r8
	ldr r2, [r3, #0x00]
	adds r5, r2, r5
	adds r5, r5, r6
	str r0, [r5, #0x00]
	movs r0, #0xA8
	lsls r0, r0, #0x01
	adds r1, r2, r0
	adds r1, r1, r6
	adds r0, r7, #0x0
	adds r0, #0x10
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	movs r1, #0xC0
	lsls r1, r1, #0x01
	adds r2, r2, r1
	adds r2, r2, r6
	ldr r1, _080B3198 @ =0x09EE981C
	adds r4, r4, r7
	adds r4, #0x20
	ldrb r0, [r4, #0x00]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r2, #0x00]
	ldr r1, _080B319C @ =0x0203AB20
	mov r2, r10
	lsls r0, r2, #0x01
	adds r0, r0, r1
	mov r3, sp
	ldrh r3, [r3, #0x00]
	strh r3, [r0, #0x00]
_080B3180:
	add sp, #0x004
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080B3190: .4byte 0x02034B4C
_080B3194: .4byte 0x08F70AB0
_080B3198: .4byte 0x09EE981C
_080B319C: .4byte 0x0203AB20
.syntax divided
