.syntax unified
	.align 2, 0
	.global func_080F80FC
	.thumb
	.thumb_func
	.type func_080F80FC, %function
func_080F80FC: @ 080F80FC
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x004
	mov r10, r0
	mov r9, r1
	adds r6, r2, #0x0
	movs r0, #0xD4
	lsls r0, r0, #0x01
	mov r1, r9
	muls r1, r0
	adds r0, r1, #0x0
	adds r0, #0x20
	mov r2, r10
	adds r7, r2, r0
	movs r3, #0xD0
	lsls r3, r3, #0x01
	adds r0, r7, r3
	mov r1, r9
	str r1, [r0, #0x00]
	movs r2, #0x9E
	lsls r2, r2, #0x01
	adds r0, r7, r2
	movs r4, #0x00
	str r4, [r0, #0x00]
	bl func_080065A4
	movs r3, #0xAC
	lsls r3, r3, #0x01
	adds r1, r7, r3
	strb r0, [r1, #0x00]
	movs r1, #0x8E
	lsls r1, r1, #0x01
	adds r0, r7, r1
	str r4, [r0, #0x00]
	movs r2, #0x90
	lsls r2, r2, #0x01
	adds r0, r7, r2
	str r4, [r0, #0x00]
	subs r3, #0x46
	adds r0, r7, r3
	strb r4, [r0, #0x00]
	adds r1, #0x3E
	adds r0, r7, r1
	movs r5, #0x00
	strh r4, [r0, #0x00]
	adds r2, #0x3C
	adds r0, r7, r2
	strh r4, [r0, #0x00]
	adds r3, #0x52
	adds r1, r7, r3
	adds r2, #0x0C
	adds r0, r7, r2
	str r4, [r0, #0x00]
	str r4, [r1, #0x00]
	mov r0, r10
	mov r1, r9
	bl func_080F800C
	movs r3, #0x98
	lsls r3, r3, #0x01
	adds r0, r7, r3
	str r4, [r0, #0x00]
	movs r1, #0x9A
	lsls r1, r1, #0x01
	adds r0, r7, r1
	str r4, [r0, #0x00]
	movs r2, #0x9C
	lsls r2, r2, #0x01
	adds r0, r7, r2
	str r4, [r0, #0x00]
	adds r3, #0x74
	adds r0, r7, r3
	strb r5, [r0, #0x00]
	cmp r6, #0x00
	beq _080F81D8
	mov r0, r9
	cmp r0, #0x01
	beq _080F81CA
	bl func_080065A4
	movs r1, #0x92
	lsls r1, r1, #0x01
	adds r2, r7, r1
	movs r4, #0x1F
	adds r1, r4, #0x0
	ands r1, r0
	lsls r1, r1, #0x08
	ldr r0, [r2, #0x00]
	subs r0, r0, r1
	str r0, [r2, #0x00]
	bl func_080065A4
	movs r2, #0x94
	lsls r2, r2, #0x01
	adds r1, r7, r2
	ands r4, r0
	lsls r4, r4, #0x08
	ldr r0, [r1, #0x00]
	subs r0, r0, r4
	str r0, [r1, #0x00]
_080F81CA:
	movs r3, #0x96
	lsls r3, r3, #0x01
	adds r1, r7, r3
	ldr r0, [r1, #0x00]
	ldr r2, _080F822C @ =0xFFFF6000
	adds r0, r0, r2
	str r0, [r1, #0x00]
_080F81D8:
	ldr r4, _080F8230 @ =0x09991F44
	movs r3, #0x92
	lsls r3, r3, #0x01
	adds r0, r7, r3
	ldr r2, [r0, #0x00]
	movs r1, #0x94
	lsls r1, r1, #0x01
	adds r0, r7, r1
	ldr r3, [r0, #0x00]
	adds r1, #0x04
	adds r0, r7, r1
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	adds r0, r7, #0x0
	adds r1, r4, #0x0
	bl func_0801B37C
	ldr r1, [r4, #0x00]
	ldr r2, _080F8234 @ =0x09991F54
	mov r3, r9
	lsls r4, r3, #0x03
	adds r0, r4, r3
	lsls r0, r0, #0x02
	adds r0, r0, r2
	ldr r2, [r0, #0x00]
	adds r0, r7, #0x0
	bl func_0801C7FC
	adds r1, r7, #0x0
	adds r1, #0xA0
	movs r0, #0x10
	strh r0, [r1, #0x00]
	adds r5, r4, #0x0
	mov r0, r9
	cmp r0, #0x00
	bne _080F8240
	ldr r0, [r7, #0x34]
	ldr r1, [r7, #0x38]
	ldr r2, _080F8238 @ =0x00000400
	ldr r3, _080F823C @ =0x00000000
	b _080F8248
	.byte 0x00, 0x00
_080F822C: .4byte 0xFFFF6000
_080F8230: .4byte 0x09991F44
_080F8234: .4byte 0x09991F54
_080F8238: .4byte 0x00000400
_080F823C: .4byte 0x00000000
_080F8240:
	ldr r0, [r7, #0x34]
	ldr r1, [r7, #0x38]
	ldr r3, _080F8354 @ =0x00000000
	ldr r2, _080F8350 @ =0x00001000
_080F8248:
	orrs r0, r2
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	ldr r0, [r7, #0x34]
	ldr r1, [r7, #0x38]
	movs r2, #0x04
	movs r3, #0x00
	orrs r0, r2
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	mov r1, r9
	cmp r1, #0x05
	bhi _080F8274
	cmp r1, #0x04
	bcc _080F8274
	movs r3, #0xAD
	lsls r3, r3, #0x01
	adds r2, r7, r3
	ldrh r1, [r2, #0x00]
	movs r0, #0x01
	orrs r0, r1
	strh r0, [r2, #0x00]
_080F8274:
	movs r0, #0xB6
	lsls r0, r0, #0x01
	adds r4, r7, r0
	adds r0, r4, #0x0
	movs r1, #0x01
	bl func_08000E64
	ldr r1, _080F8358 @ =0x09EDAE88
	adds r0, r4, #0x0
	adds r2, r7, #0x0
	bl func_08000E14
	ldr r6, _080F835C @ =0x09991F54
	mov r1, r9
	adds r4, r5, r1
	lsls r4, r4, #0x02
	adds r0, r6, #0x0
	adds r0, #0x1C
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	mov r8, r0
	adds r0, r4, r6
	ldrh r1, [r0, #0x20]
	mov r0, r8
	bl func_08003524
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r6, #0x0
	adds r1, #0x14
	adds r1, r4, r1
	ldr r1, [r1, #0x00]
	bl func_080028F8
	movs r2, #0xCC
	lsls r2, r2, #0x01
	adds r1, r7, r2
	str r0, [r1, #0x00]
	movs r3, #0xC0
	lsls r3, r3, #0x01
	adds r5, r7, r3
	adds r6, #0x18
	adds r4, r4, r6
	ldr r1, [r4, #0x00]
	adds r0, r5, #0x0
	mov r2, r8
	bl func_08005968
	adds r0, r5, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
	adds r0, r5, #0x0
	bl func_08005AFC
	movs r2, #0xCE
	lsls r2, r2, #0x01
	adds r1, r7, r2
	str r0, [r1, #0x00]
	mov r3, r9
	cmp r3, #0x00
	bne _080F8332
	ldr r5, _080F8360 @ =0x09EF9728
	adds r0, r5, #0x0
	movs r1, #0x04
	bl func_08003524
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080F8364 @ =0x099999AC
	bl func_080028F8
	ldr r1, _080F8368 @ =0x00000A28
	add r1, r10
	str r0, [r1, #0x00]
	movs r4, #0xA1
	lsls r4, r4, #0x04
	add r4, r10
	ldr r1, _080F836C @ =0x09EF9738
	adds r0, r4, #0x0
	adds r2, r5, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
	adds r0, r4, #0x0
	bl func_08005AFC
	ldr r1, _080F8370 @ =0x00000A2C
	add r1, r10
	str r0, [r1, #0x00]
_080F8332:
	adds r0, r7, #0x0
	adds r0, #0x40
	movs r1, #0x08
	movs r2, #0x08
	movs r3, #0x10
	bl func_080122AC
	add sp, #0x004
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080F8350: .4byte 0x00001000
_080F8354: .4byte 0x00000000
_080F8358: .4byte 0x09EDAE88
_080F835C: .4byte 0x09991F54
_080F8360: .4byte 0x09EF9728
_080F8364: .4byte 0x099999AC
_080F8368: .4byte 0x00000A28
_080F836C: .4byte 0x09EF9738
_080F8370: .4byte 0x00000A2C
.syntax divided
