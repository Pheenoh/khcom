.syntax unified
	.align 2, 0
	.global func_0809D458
	.thumb
	.thumb_func
	.type func_0809D458, %function
func_0809D458: @ 0809D458
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x048
	adds r7, r3, #0x0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x02C]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x030]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #0x034]
	cmp r7, #0x00
	bge _0809D47E
	b _0809D668
_0809D47E:
	adds r0, r7, #0x0
	ldr r1, _0809D658 @ =0x00989680
	bl __divsi3
	mov r8, r0
	str r0, [sp, #0x000]
	ldr r1, _0809D65C @ =0x000F4240
	adds r0, r7, #0x0
	bl __divsi3
	mov r10, r0
	mov r1, r8
	lsls r0, r1, #0x02
	add r0, r8
	lsls r0, r0, #0x01
	mov r2, r10
	subs r2, r2, r0
	mov r10, r2
	str r2, [sp, #0x004]
	adds r0, r7, #0x0
	ldr r1, _0809D660 @ =0x000186A0
	bl __divsi3
	mov r9, r0
	movs r3, #0x64
	mov r0, r8
	muls r0, r3
	mov r4, r9
	subs r4, r4, r0
	mov r5, r10
	lsls r0, r5, #0x02
	add r0, r10
	lsls r0, r0, #0x01
	subs r4, r4, r0
	mov r9, r4
	str r4, [sp, #0x008]
	adds r0, r7, #0x0
	ldr r1, _0809D664 @ =0x00002710
	bl __divsi3
	adds r6, r0, #0x0
	mov r1, r8
	lsls r0, r1, #0x05
	subs r1, r0, r1
	str r1, [sp, #0x038]
	lsls r0, r1, #0x02
	add r0, r8
	lsls r0, r0, #0x03
	subs r6, r6, r0
	movs r2, #0x64
	mov r0, r10
	muls r0, r2
	subs r6, r6, r0
	lsls r0, r4, #0x02
	add r0, r9
	lsls r0, r0, #0x01
	subs r6, r6, r0
	str r6, [sp, #0x00C]
	movs r1, #0xFA
	lsls r1, r1, #0x02
	adds r0, r7, #0x0
	bl __divsi3
	adds r4, r0, #0x0
	ldr r3, _0809D664 @ =0x00002710
	mov r0, r8
	muls r0, r3
	subs r4, r4, r0
	lsls r0, r5, #0x05
	subs r5, r0, r5
	str r5, [sp, #0x03C]
	lsls r0, r5, #0x02
	add r0, r10
	lsls r0, r0, #0x03
	subs r4, r4, r0
	movs r5, #0x64
	mov r0, r9
	muls r0, r5
	subs r4, r4, r0
	lsls r0, r6, #0x02
	adds r0, r0, r6
	lsls r0, r0, #0x01
	subs r4, r4, r0
	str r4, [sp, #0x010]
	adds r0, r7, #0x0
	movs r1, #0x64
	bl __divsi3
	adds r5, r0, #0x0
	ldr r1, _0809D660 @ =0x000186A0
	mov r0, r8
	muls r0, r1
	subs r5, r5, r0
	ldr r2, _0809D664 @ =0x00002710
	mov r0, r10
	muls r0, r2
	subs r5, r5, r0
	mov r3, r9
	lsls r0, r3, #0x05
	subs r0, r0, r3
	lsls r0, r0, #0x02
	add r0, r9
	lsls r0, r0, #0x03
	subs r5, r5, r0
	movs r1, #0x64
	adds r0, r6, #0x0
	muls r0, r1
	subs r5, r5, r0
	lsls r0, r4, #0x02
	adds r0, r0, r4
	lsls r0, r0, #0x01
	subs r5, r5, r0
	str r5, [sp, #0x014]
	adds r0, r7, #0x0
	movs r1, #0x0A
	bl __divsi3
	ldr r2, [sp, #0x038]
	lsls r1, r2, #0x06
	subs r1, r1, r2
	lsls r1, r1, #0x03
	add r1, r8
	lsls r1, r1, #0x06
	subs r0, r0, r1
	ldr r3, _0809D660 @ =0x000186A0
	mov r1, r10
	muls r1, r3
	subs r0, r0, r1
	ldr r2, _0809D664 @ =0x00002710
	mov r1, r9
	muls r1, r2
	subs r0, r0, r1
	lsls r1, r6, #0x05
	subs r1, r1, r6
	lsls r1, r1, #0x02
	adds r1, r1, r6
	lsls r1, r1, #0x03
	subs r0, r0, r1
	movs r3, #0x64
	adds r1, r4, #0x0
	muls r1, r3
	subs r0, r0, r1
	lsls r1, r5, #0x02
	adds r1, r1, r5
	lsls r1, r1, #0x01
	subs r0, r0, r1
	str r0, [sp, #0x018]
	ldr r1, _0809D658 @ =0x00989680
	mov r2, r8
	muls r2, r1
	ldr r3, [sp, #0x03C]
	lsls r1, r3, #0x06
	subs r1, r1, r3
	lsls r1, r1, #0x03
	add r1, r10
	lsls r1, r1, #0x06
	adds r2, r2, r1
	ldr r3, _0809D660 @ =0x000186A0
	mov r1, r9
	muls r1, r3
	adds r2, r2, r1
	ldr r3, _0809D664 @ =0x00002710
	adds r1, r6, #0x0
	muls r1, r3
	adds r2, r2, r1
	lsls r1, r4, #0x05
	subs r1, r1, r4
	lsls r1, r1, #0x02
	adds r1, r1, r4
	lsls r1, r1, #0x03
	adds r2, r2, r1
	movs r4, #0x64
	adds r1, r5, #0x0
	muls r1, r4
	adds r2, r2, r1
	lsls r1, r0, #0x02
	adds r1, r1, r0
	lsls r1, r1, #0x01
	adds r2, r2, r1
	subs r2, r7, r2
	str r2, [sp, #0x01C]
	add r1, sp, #0x020
	movs r5, #0x30
	add r8, r5
	movs r2, #0x00
	mov r7, r8
	strb r7, [r1, #0x00]
	ldr r0, [sp, #0x004]
	adds r0, #0x30
	strb r0, [r1, #0x01]
	ldr r0, [sp, #0x008]
	adds r0, #0x30
	strb r0, [r1, #0x02]
	ldr r0, [sp, #0x00C]
	adds r0, #0x30
	strb r0, [r1, #0x03]
	ldr r0, [sp, #0x010]
	adds r0, #0x30
	strb r0, [r1, #0x04]
	ldr r0, [sp, #0x014]
	adds r0, #0x30
	strb r0, [r1, #0x05]
	ldr r0, [sp, #0x018]
	adds r0, #0x30
	strb r0, [r1, #0x06]
	ldr r0, [sp, #0x01C]
	adds r0, #0x30
	strb r0, [r1, #0x07]
	strb r2, [r1, #0x08]
	movs r3, #0x00
	mov r0, r8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r6, r1, #0x0
	ldr r1, [sp, #0x02C]
	lsls r4, r1, #0x18
	ldr r2, [sp, #0x030]
	lsls r1, r2, #0x18
	ldr r5, [sp, #0x034]
	lsls r2, r5, #0x18
	cmp r0, #0x30
	bhi _0809D64A
	adds r5, r6, #0x0
_0809D63C:
	adds r3, #0x01
	cmp r3, #0x06
	bgt _0809D64A
	adds r0, r5, r3
	ldrb r0, [r0, #0x00]
	cmp r0, #0x30
	bls _0809D63C
_0809D64A:
	lsrs r0, r4, #0x18
	lsrs r1, r1, #0x18
	lsrs r2, r2, #0x18
	adds r3, r6, r3
	bl func_0809D2B0
	b _0809D84A
_0809D658: .4byte 0x00989680
_0809D65C: .4byte 0x000F4240
_0809D660: .4byte 0x000186A0
_0809D664: .4byte 0x00002710
_0809D668:
	ldr r1, _0809D85C @ =0xFF676980
	adds r0, r7, #0x0
	bl __divsi3
	mov r10, r0
	str r0, [sp, #0x000]
	ldr r1, _0809D860 @ =0xFFF0BDC0
	adds r0, r7, #0x0
	bl __divsi3
	mov r9, r0
	mov r1, r10
	lsls r0, r1, #0x02
	add r0, r10
	lsls r0, r0, #0x01
	mov r2, r9
	subs r2, r2, r0
	mov r9, r2
	str r2, [sp, #0x004]
	ldr r1, _0809D864 @ =0xFFFE7960
	adds r0, r7, #0x0
	bl __divsi3
	mov r8, r0
	movs r3, #0x64
	mov r0, r10
	muls r0, r3
	mov r4, r8
	subs r4, r4, r0
	mov r5, r9
	lsls r0, r5, #0x02
	add r0, r9
	lsls r0, r0, #0x01
	subs r4, r4, r0
	mov r8, r4
	str r4, [sp, #0x008]
	ldr r1, _0809D868 @ =0xFFFFD8F0
	adds r0, r7, #0x0
	bl __divsi3
	adds r6, r0, #0x0
	mov r1, r10
	lsls r0, r1, #0x05
	subs r1, r0, r1
	str r1, [sp, #0x040]
	lsls r0, r1, #0x02
	add r0, r10
	lsls r0, r0, #0x03
	subs r6, r6, r0
	movs r2, #0x64
	mov r0, r9
	muls r0, r2
	subs r6, r6, r0
	lsls r0, r4, #0x02
	add r0, r8
	lsls r0, r0, #0x01
	subs r6, r6, r0
	str r6, [sp, #0x00C]
	ldr r1, _0809D86C @ =0xFFFFFC18
	adds r0, r7, #0x0
	bl __divsi3
	adds r4, r0, #0x0
	ldr r3, _0809D870 @ =0x00002710
	mov r0, r10
	muls r0, r3
	subs r4, r4, r0
	lsls r0, r5, #0x05
	subs r5, r0, r5
	str r5, [sp, #0x044]
	lsls r0, r5, #0x02
	add r0, r9
	lsls r0, r0, #0x03
	subs r4, r4, r0
	movs r5, #0x64
	mov r0, r8
	muls r0, r5
	subs r4, r4, r0
	lsls r0, r6, #0x02
	adds r0, r0, r6
	lsls r0, r0, #0x01
	subs r4, r4, r0
	str r4, [sp, #0x010]
	movs r1, #0x64
	negs r1, r1
	adds r0, r7, #0x0
	bl __divsi3
	adds r5, r0, #0x0
	ldr r1, _0809D874 @ =0x000186A0
	mov r0, r10
	muls r0, r1
	subs r5, r5, r0
	ldr r2, _0809D870 @ =0x00002710
	mov r0, r9
	muls r0, r2
	subs r5, r5, r0
	mov r3, r8
	lsls r0, r3, #0x05
	subs r0, r0, r3
	lsls r0, r0, #0x02
	add r0, r8
	lsls r0, r0, #0x03
	subs r5, r5, r0
	movs r1, #0x64
	adds r0, r6, #0x0
	muls r0, r1
	subs r5, r5, r0
	lsls r0, r4, #0x02
	adds r0, r0, r4
	lsls r0, r0, #0x01
	subs r5, r5, r0
	str r5, [sp, #0x014]
	subs r1, #0x6E
	adds r0, r7, #0x0
	bl __divsi3
	ldr r2, [sp, #0x040]
	lsls r1, r2, #0x06
	subs r1, r1, r2
	lsls r1, r1, #0x03
	add r1, r10
	lsls r1, r1, #0x06
	subs r0, r0, r1
	ldr r3, _0809D874 @ =0x000186A0
	mov r1, r9
	muls r1, r3
	subs r0, r0, r1
	ldr r2, _0809D870 @ =0x00002710
	mov r1, r8
	muls r1, r2
	subs r0, r0, r1
	lsls r1, r6, #0x05
	subs r1, r1, r6
	lsls r1, r1, #0x02
	adds r1, r1, r6
	lsls r1, r1, #0x03
	subs r0, r0, r1
	movs r3, #0x64
	adds r1, r4, #0x0
	muls r1, r3
	subs r0, r0, r1
	lsls r1, r5, #0x02
	adds r1, r1, r5
	lsls r1, r1, #0x01
	subs r0, r0, r1
	str r0, [sp, #0x018]
	negs r3, r7
	ldr r1, _0809D878 @ =0x00989680
	mov r2, r10
	muls r2, r1
	ldr r7, [sp, #0x044]
	lsls r1, r7, #0x06
	subs r1, r1, r7
	lsls r1, r1, #0x03
	add r1, r9
	lsls r1, r1, #0x06
	adds r2, r2, r1
	ldr r7, _0809D874 @ =0x000186A0
	mov r1, r8
	muls r1, r7
	adds r2, r2, r1
	ldr r7, _0809D870 @ =0x00002710
	adds r1, r6, #0x0
	muls r1, r7
	adds r2, r2, r1
	lsls r1, r4, #0x05
	subs r1, r1, r4
	lsls r1, r1, #0x02
	adds r1, r1, r4
	lsls r1, r1, #0x03
	adds r2, r2, r1
	movs r4, #0x64
	adds r1, r5, #0x0
	muls r1, r4
	adds r2, r2, r1
	lsls r1, r0, #0x02
	adds r1, r1, r0
	lsls r1, r1, #0x01
	adds r2, r2, r1
	subs r3, r3, r2
	str r3, [sp, #0x01C]
	add r1, sp, #0x020
	movs r2, #0x00
	movs r0, #0x2D
	strb r0, [r1, #0x00]
	ldr r0, [sp, #0x000]
	adds r0, #0x30
	strb r0, [r1, #0x01]
	ldr r0, [sp, #0x004]
	adds r0, #0x30
	strb r0, [r1, #0x02]
	ldr r0, [sp, #0x008]
	adds r0, #0x30
	strb r0, [r1, #0x03]
	ldr r0, [sp, #0x00C]
	adds r0, #0x30
	strb r0, [r1, #0x04]
	ldr r0, [sp, #0x010]
	adds r0, #0x30
	strb r0, [r1, #0x05]
	ldr r0, [sp, #0x014]
	adds r0, #0x30
	strb r0, [r1, #0x06]
	ldr r0, [sp, #0x018]
	adds r0, #0x30
	strb r0, [r1, #0x07]
	ldr r0, [sp, #0x01C]
	adds r0, #0x30
	strb r0, [r1, #0x08]
	strb r2, [r1, #0x09]
	movs r3, #0x01
	mov r0, sp
	adds r0, #0x21
	ldrb r0, [r0, #0x00]
	adds r6, r1, #0x0
	ldr r5, [sp, #0x02C]
	lsls r4, r5, #0x18
	ldr r7, [sp, #0x030]
	lsls r1, r7, #0x18
	ldr r5, [sp, #0x034]
	lsls r2, r5, #0x18
	cmp r0, #0x30
	bhi _0809D838
	adds r5, r6, #0x0
_0809D82A:
	adds r3, #0x01
	cmp r3, #0x07
	bgt _0809D838
	adds r0, r5, r3
	ldrb r0, [r0, #0x00]
	cmp r0, #0x30
	bls _0809D82A
_0809D838:
	subs r3, #0x01
	adds r3, r6, r3
	movs r0, #0x2D
	strb r0, [r3, #0x00]
	lsrs r0, r4, #0x18
	lsrs r1, r1, #0x18
	lsrs r2, r2, #0x18
	bl func_0809D2B0
_0809D84A:
	add sp, #0x048
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0809D85C: .4byte 0xFF676980
_0809D860: .4byte 0xFFF0BDC0
_0809D864: .4byte 0xFFFE7960
_0809D868: .4byte 0xFFFFD8F0
_0809D86C: .4byte 0xFFFFFC18
_0809D870: .4byte 0x00002710
_0809D874: .4byte 0x000186A0
_0809D878: .4byte 0x00989680
.syntax divided
