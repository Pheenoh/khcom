.syntax unified
	.align 2, 0
	.global func_08098014
	.thumb
	.thumb_func
	.type func_08098014, %function
func_08098014: @ 08098014
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x004
	adds r7, r0, #0x0
	mov r8, r1
	movs r6, #0x00
	str r6, [sp, #0x000]
	ldr r2, _0809808C @ =0x0500000D
	mov r0, sp
	adds r1, r7, #0x0
	bl CpuSet
	mov r1, r8
	ldrb r0, [r1, #0x00]
	cmp r0, #0xFF
	beq _08098098
	lsls r4, r0, #0x01
	adds r4, r4, r0
	lsls r4, r4, #0x03
	adds r4, r4, r0
	lsls r4, r4, #0x04
	ldr r0, _08098090 @ =0x09EE4C80
	adds r4, r4, r0
	ldrb r0, [r4, #0x1E]
	lsls r5, r0, #0x03
	subs r5, r5, r0
	lsls r5, r5, #0x02
	ldr r0, _08098094 @ =0x09EE4BF4
	adds r5, r5, r0
	ldr r0, [r4, #0x00]
	ldrh r1, [r4, #0x18]
	bl LoadObjTiles
	str r0, [r7, #0x00]
	ldr r0, [r4, #0x04]
	ldrh r1, [r4, #0x1A]
	bl LoadObjPalette
	str r0, [r7, #0x0C]
	ldr r0, [r4, #0x08]
	ldr r0, [r0, #0x00]
	str r0, [r7, #0x18]
	ldr r0, [r5, #0x00]
	ldrh r1, [r5, #0x14]
	bl LoadObjTiles
	str r0, [r7, #0x04]
	ldr r0, [r5, #0x04]
	ldrh r1, [r5, #0x16]
	bl LoadObjPalette
	str r0, [r7, #0x10]
	ldr r0, [r5, #0x08]
	ldr r0, [r0, #0x00]
	str r0, [r7, #0x1C]
	str r6, [r7, #0x08]
	str r6, [r7, #0x14]
	b _080984C2
	.byte 0x00, 0x00
_0809808C: .4byte 0x0500000D
_08098090: .4byte 0x09EE4C80
_08098094: .4byte 0x09EE4BF4
_08098098:
	str r6, [r7, #0x00]
	str r6, [r7, #0x0C]
	str r6, [r7, #0x18]
	str r6, [r7, #0x08]
	str r6, [r7, #0x14]
	mov r2, r8
	ldrb r0, [r2, #0x01]
	cmp r0, #0x00
	bne _080980B2
	str r6, [r7, #0x04]
	str r6, [r7, #0x10]
	str r6, [r7, #0x1C]
	b _08098112
_080980B2:
	mov r1, r8
	ldrb r0, [r1, #0x01]
	lsls r4, r0, #0x03
	subs r4, r4, r0
	lsls r4, r4, #0x02
	ldr r0, _080980F8 @ =0x09EE4BF4
	adds r4, r4, r0
	ldr r0, [r4, #0x0C]
	ldrh r1, [r4, #0x18]
	bl LoadObjTiles
	str r0, [r7, #0x04]
	ldr r0, [r4, #0x04]
	ldrh r1, [r4, #0x16]
	bl LoadObjPalette
	str r0, [r7, #0x10]
	ldr r0, [r4, #0x10]
	ldr r0, [r0, #0x00]
	str r0, [r7, #0x1C]
	str r6, [r7, #0x08]
	str r6, [r7, #0x00]
	str r6, [r7, #0x0C]
	str r6, [r7, #0x18]
	str r6, [r7, #0x14]
	mov r2, r8
	ldrb r0, [r2, #0x01]
	cmp r0, #0x02
	beq _08098106
	cmp r0, #0x02
	bgt _080980FC
	cmp r0, #0x01
	beq _08098102
	b _0809810E
	.byte 0x00, 0x00
_080980F8: .4byte 0x09EE4BF4
_080980FC:
	cmp r0, #0x03
	beq _0809810A
	b _0809810E
_08098102:
	movs r0, #0x01
	b _08098112
_08098106:
	movs r0, #0x02
	b _08098112
_0809810A:
	movs r0, #0x03
	b _08098112
_0809810E:
	mov r1, r8
	ldrb r0, [r1, #0x01]
_08098112:
	adds r1, r7, #0x0
	adds r1, #0x32
	movs r4, #0x00
	strb r0, [r1, #0x00]
	mov r2, r8
	ldrb r0, [r2, #0x02]
	cmp r0, #0x00
	bne _08098124
	b _080984C2
_08098124:
	cmp r0, #0x02
	beq _08098218
	cmp r0, #0x02
	bgt _08098132
	cmp r0, #0x01
	beq _08098140
	b _0809848C
_08098132:
	cmp r0, #0x03
	bne _08098138
	b _080982F0
_08098138:
	cmp r0, #0x04
	bne _0809813E
	b _080983D8
_0809813E:
	b _0809848C
_08098140:
	mov r1, r8
	ldrb r0, [r1, #0x03]
	cmp r0, #0x09
	bhi _08098198
	movs r0, #0x80
	lsls r0, r0, #0x01
	bl func_080038C8
	str r0, [r7, #0x08]
	ldr r1, _0809818C @ =0x09EF1198
	ldr r1, [r1, #0x04]
	ldr r2, _08098190 @ =0x0950C478
	bl func_080038E4
	str r4, [r7, #0x20]
	ldr r2, [r7, #0x08]
	mov r0, r8
	ldrb r1, [r0, #0x03]
	lsls r1, r1, #0x07
	ldr r0, [r2, #0x00]
	adds r0, r0, r1
	ldrh r1, [r2, #0x06]
	adds r1, #0x04
	lsls r1, r1, #0x05
	ldr r4, _08098194 @ =0x06010000
	adds r1, r1, r4
	movs r2, #0x80
	bl RequestDma3Copy
	ldr r1, [r7, #0x08]
	ldr r0, [r1, #0x00]
	movs r2, #0xA0
	lsls r2, r2, #0x03
	adds r0, r0, r2
	ldrh r1, [r1, #0x06]
	lsls r1, r1, #0x05
	adds r1, r1, r4
	b _080983C2
_0809818C: .4byte 0x09EF1198
_08098190: .4byte 0x0950C478
_08098194: .4byte 0x06010000
_08098198:
	movs r0, #0xC0
	lsls r0, r0, #0x01
	bl func_080038C8
	str r0, [r7, #0x08]
	ldr r1, _0809820C @ =0x09EF1198
	ldr r1, [r1, #0x0C]
	ldr r2, _08098210 @ =0x0950C478
	bl func_080038E4
	str r4, [r7, #0x20]
	ldr r4, [r7, #0x08]
	mov r1, r8
	ldrb r0, [r1, #0x03]
	movs r1, #0x0A
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x11
	ldr r2, [r4, #0x00]
	adds r2, r2, r0
	ldrh r1, [r4, #0x06]
	adds r1, #0x04
	lsls r1, r1, #0x05
	ldr r5, _08098214 @ =0x06010000
	adds r1, r1, r5
	adds r0, r2, #0x0
	movs r2, #0x80
	bl RequestDma3Copy
	ldr r6, [r7, #0x08]
	mov r2, r8
	ldrb r4, [r2, #0x03]
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #0x02
	adds r1, r1, r0
	lsls r1, r1, #0x01
	subs r4, r4, r1
	lsls r4, r4, #0x07
	ldr r0, [r6, #0x00]
	adds r0, r0, r4
	ldrh r1, [r6, #0x06]
	adds r1, #0x08
	lsls r1, r1, #0x05
	adds r1, r1, r5
	movs r2, #0x80
	bl RequestDma3Copy
	ldr r1, [r7, #0x08]
	ldr r0, [r1, #0x00]
	movs r2, #0xA0
	lsls r2, r2, #0x03
	b _080983BA
_0809820C: .4byte 0x09EF1198
_08098210: .4byte 0x0950C478
_08098214: .4byte 0x06010000
_08098218:
	mov r1, r8
	ldrb r0, [r1, #0x03]
	cmp r0, #0x09
	bhi _08098270
	movs r0, #0x80
	lsls r0, r0, #0x01
	bl func_080038C8
	str r0, [r7, #0x08]
	ldr r1, _08098264 @ =0x09EF1198
	ldr r1, [r1, #0x04]
	ldr r2, _08098268 @ =0x0950C478
	bl func_080038E4
	str r4, [r7, #0x20]
	ldr r2, [r7, #0x08]
	mov r0, r8
	ldrb r1, [r0, #0x03]
	lsls r1, r1, #0x07
	ldr r0, [r2, #0x00]
	adds r0, r0, r1
	ldrh r1, [r2, #0x06]
	adds r1, #0x04
	lsls r1, r1, #0x05
	ldr r4, _0809826C @ =0x06010000
	adds r1, r1, r4
	movs r2, #0x80
	bl RequestDma3Copy
	ldr r1, [r7, #0x08]
	ldr r0, [r1, #0x00]
	movs r2, #0xB0
	lsls r2, r2, #0x03
	adds r0, r0, r2
	ldrh r1, [r1, #0x06]
	lsls r1, r1, #0x05
	adds r1, r1, r4
	b _080983C2
_08098264: .4byte 0x09EF1198
_08098268: .4byte 0x0950C478
_0809826C: .4byte 0x06010000
_08098270:
	movs r0, #0xC0
	lsls r0, r0, #0x01
	bl func_080038C8
	str r0, [r7, #0x08]
	ldr r1, _080982E4 @ =0x09EF1198
	ldr r1, [r1, #0x0C]
	ldr r2, _080982E8 @ =0x0950C478
	bl func_080038E4
	str r4, [r7, #0x20]
	ldr r4, [r7, #0x08]
	mov r1, r8
	ldrb r0, [r1, #0x03]
	movs r1, #0x0A
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x11
	ldr r2, [r4, #0x00]
	adds r2, r2, r0
	ldrh r1, [r4, #0x06]
	adds r1, #0x04
	lsls r1, r1, #0x05
	ldr r5, _080982EC @ =0x06010000
	adds r1, r1, r5
	adds r0, r2, #0x0
	movs r2, #0x80
	bl RequestDma3Copy
	ldr r6, [r7, #0x08]
	mov r2, r8
	ldrb r4, [r2, #0x03]
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #0x02
	adds r1, r1, r0
	lsls r1, r1, #0x01
	subs r4, r4, r1
	lsls r4, r4, #0x07
	ldr r0, [r6, #0x00]
	adds r0, r0, r4
	ldrh r1, [r6, #0x06]
	adds r1, #0x08
	lsls r1, r1, #0x05
	adds r1, r1, r5
	movs r2, #0x80
	bl RequestDma3Copy
	ldr r1, [r7, #0x08]
	ldr r0, [r1, #0x00]
	movs r2, #0xB0
	lsls r2, r2, #0x03
	b _080983BA
_080982E4: .4byte 0x09EF1198
_080982E8: .4byte 0x0950C478
_080982EC: .4byte 0x06010000
_080982F0:
	mov r1, r8
	ldrb r0, [r1, #0x03]
	cmp r0, #0x09
	bhi _08098348
	movs r0, #0x80
	lsls r0, r0, #0x01
	bl func_080038C8
	str r0, [r7, #0x08]
	ldr r1, _0809833C @ =0x09EF1198
	ldr r1, [r1, #0x04]
	ldr r2, _08098340 @ =0x0950C478
	bl func_080038E4
	str r4, [r7, #0x20]
	ldr r2, [r7, #0x08]
	mov r0, r8
	ldrb r1, [r0, #0x03]
	lsls r1, r1, #0x07
	ldr r0, [r2, #0x00]
	adds r0, r0, r1
	ldrh r1, [r2, #0x06]
	adds r1, #0x04
	lsls r1, r1, #0x05
	ldr r4, _08098344 @ =0x06010000
	adds r1, r1, r4
	movs r2, #0x80
	bl RequestDma3Copy
	ldr r1, [r7, #0x08]
	ldr r0, [r1, #0x00]
	movs r2, #0xC0
	lsls r2, r2, #0x03
	adds r0, r0, r2
	ldrh r1, [r1, #0x06]
	lsls r1, r1, #0x05
	adds r1, r1, r4
	b _080983C2
_0809833C: .4byte 0x09EF1198
_08098340: .4byte 0x0950C478
_08098344: .4byte 0x06010000
_08098348:
	movs r0, #0xC0
	lsls r0, r0, #0x01
	bl func_080038C8
	str r0, [r7, #0x08]
	ldr r1, _080983CC @ =0x09EF1198
	ldr r1, [r1, #0x0C]
	ldr r2, _080983D0 @ =0x0950C478
	bl func_080038E4
	str r4, [r7, #0x20]
	ldr r4, [r7, #0x08]
	mov r1, r8
	ldrb r0, [r1, #0x03]
	movs r1, #0x0A
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x11
	ldr r2, [r4, #0x00]
	adds r2, r2, r0
	ldrh r1, [r4, #0x06]
	adds r1, #0x04
	lsls r1, r1, #0x05
	ldr r5, _080983D4 @ =0x06010000
	adds r1, r1, r5
	adds r0, r2, #0x0
	movs r2, #0x80
	bl RequestDma3Copy
	ldr r6, [r7, #0x08]
	mov r2, r8
	ldrb r4, [r2, #0x03]
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #0x02
	adds r1, r1, r0
	lsls r1, r1, #0x01
	subs r4, r4, r1
	lsls r4, r4, #0x07
	ldr r0, [r6, #0x00]
	adds r0, r0, r4
	ldrh r1, [r6, #0x06]
	adds r1, #0x08
	lsls r1, r1, #0x05
	adds r1, r1, r5
	movs r2, #0x80
	bl RequestDma3Copy
	ldr r1, [r7, #0x08]
	ldr r0, [r1, #0x00]
	movs r2, #0xC0
	lsls r2, r2, #0x03
_080983BA:
	adds r0, r0, r2
	ldrh r1, [r1, #0x06]
	lsls r1, r1, #0x05
	adds r1, r1, r5
_080983C2:
	movs r2, #0x80
	bl RequestDma3Copy
	b _0809848C
	.byte 0x00, 0x00
_080983CC: .4byte 0x09EF1198
_080983D0: .4byte 0x0950C478
_080983D4: .4byte 0x06010000
_080983D8:
	mov r1, r8
	ldrb r0, [r1, #0x03]
	cmp r0, #0x09
	bhi _0809841C
	movs r0, #0x80
	bl func_080038C8
	str r0, [r7, #0x08]
	ldr r1, _08098410 @ =0x09EF1198
	ldr r1, [r1, #0x00]
	ldr r2, _08098414 @ =0x0950C478
	bl func_080038E4
	str r4, [r7, #0x20]
	ldr r2, [r7, #0x08]
	mov r0, r8
	ldrb r1, [r0, #0x03]
	lsls r1, r1, #0x07
	ldr r0, [r2, #0x00]
	adds r0, r0, r1
	ldrh r1, [r2, #0x06]
	lsls r1, r1, #0x05
	ldr r2, _08098418 @ =0x06010000
	adds r1, r1, r2
	movs r2, #0x80
	bl RequestDma3Copy
	b _08098484
_08098410: .4byte 0x09EF1198
_08098414: .4byte 0x0950C478
_08098418: .4byte 0x06010000
_0809841C:
	movs r0, #0x80
	lsls r0, r0, #0x01
	bl func_080038C8
	str r0, [r7, #0x08]
	ldr r1, _080984D0 @ =0x09EF1198
	ldr r1, [r1, #0x08]
	ldr r2, _080984D4 @ =0x0950C478
	bl func_080038E4
	str r4, [r7, #0x20]
	ldr r4, [r7, #0x08]
	mov r1, r8
	ldrb r0, [r1, #0x03]
	movs r1, #0x0A
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x11
	ldr r2, [r4, #0x00]
	adds r2, r2, r0
	ldrh r1, [r4, #0x06]
	lsls r1, r1, #0x05
	ldr r6, _080984D8 @ =0x06010000
	adds r1, r1, r6
	adds r0, r2, #0x0
	movs r2, #0x80
	bl RequestDma3Copy
	ldr r5, [r7, #0x08]
	mov r2, r8
	ldrb r4, [r2, #0x03]
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #0x02
	adds r1, r1, r0
	lsls r1, r1, #0x01
	subs r4, r4, r1
	lsls r4, r4, #0x07
	ldr r0, [r5, #0x00]
	adds r0, r0, r4
	ldrh r1, [r5, #0x06]
	adds r1, #0x04
	lsls r1, r1, #0x05
	adds r1, r1, r6
	movs r2, #0x80
	bl RequestDma3Copy
_08098484:
	mov r1, r8
	ldrb r0, [r1, #0x03]
	strh r0, [r7, #0x2E]
	strh r0, [r7, #0x30]
_0809848C:
	movs r0, #0x00
	str r0, [r7, #0x00]
	str r0, [r7, #0x0C]
	str r0, [r7, #0x18]
	ldr r5, _080984DC @ =0x09618D38
	adds r0, r5, #0x0
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r7, #0x14]
	ldr r0, [r7, #0x04]
	cmp r0, #0x00
	bne _080984C2
	ldr r4, _080984E0 @ =0x08F70A10
	ldr r0, [r4, #0x10]
	movs r1, #0xC0
	lsls r1, r1, #0x02
	bl LoadObjTiles
	str r0, [r7, #0x04]
	adds r0, r5, #0x0
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r7, #0x10]
	ldr r0, [r4, #0x04]
	str r0, [r7, #0x1C]
_080984C2:
	add sp, #0x004
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080984D0: .4byte 0x09EF1198
_080984D4: .4byte 0x0950C478
_080984D8: .4byte 0x06010000
_080984DC: .4byte 0x09618D38
_080984E0: .4byte 0x08F70A10
.syntax divided
