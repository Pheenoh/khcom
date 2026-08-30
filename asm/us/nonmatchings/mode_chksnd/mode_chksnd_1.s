.syntax unified
	.align 2, 0
	.global mode_chksnd_1
	.thumb
	.thumb_func
	.type mode_chksnd_1, %function
mode_chksnd_1: @ 0800BA28
	push {r4, r5, lr}
	bl func_08001390
	movs r1, #0x02
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	cmp r4, #0x00
	beq _0800BA48
	ldr r0, _0800BA44 @ =0x09ECEB64
	movs r1, #0x00
	bl func_080010CC
	b _0800BAFC
_0800BA44: .4byte 0x09ECEB64
_0800BA48:
	bl func_0800139C
	movs r1, #0x20
	ands r1, r0
	cmp r1, #0x00
	beq _0800BA5C
	ldr r1, _0800BB04 @ =0x020348B4
	ldrh r0, [r1, #0x00]
	subs r0, #0x01
	strh r0, [r1, #0x00]
_0800BA5C:
	bl func_0800139C
	movs r1, #0x10
	ands r1, r0
	cmp r1, #0x00
	beq _0800BA70
	ldr r1, _0800BB04 @ =0x020348B4
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
_0800BA70:
	bl func_08001390
	movs r1, #0x01
	ands r1, r0
	cmp r1, #0x00
	beq _0800BA8E
	ldr r1, _0800BB08 @ =0x09ED8644
	ldr r0, _0800BB04 @ =0x020348B4
	movs r2, #0x00
	ldsh r0, [r0, r2]
	lsls r0, r0, #0x03
	adds r0, r0, r1
	ldrh r0, [r0, #0x04]
	bl func_0811FE70
_0800BA8E:
	ldr r5, _0800BB04 @ =0x020348B4
	movs r1, #0x00
	ldsh r0, [r5, r1]
	cmp r0, #0x00
	bge _0800BAA0
	movs r2, #0x9E
	lsls r2, r2, #0x02
	adds r0, r2, #0x0
	strh r0, [r5, #0x00]
_0800BAA0:
	ldrh r1, [r5, #0x00]
	movs r0, #0x9E
	lsls r0, r0, #0x02
	cmp r1, r0
	bls _0800BAAC
	strh r4, [r5, #0x00]
_0800BAAC:
	ldr r3, _0800BB0C @ =0x081309B0
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x00
	bl func_0809D2B0
	ldr r4, _0800BB08 @ =0x09ED8644
	movs r1, #0x00
	ldsh r0, [r5, r1]
	lsls r0, r0, #0x03
	adds r0, r0, r4
	ldrh r3, [r0, #0x04]
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x00
	bl func_0809D458
	ldr r3, _0800BB10 @ =0x081309D0
	movs r0, #0x05
	movs r1, #0x00
	movs r2, #0x00
	bl func_0809D2B0
	movs r2, #0x00
	ldsh r0, [r5, r2]
	lsls r0, r0, #0x03
	adds r0, r0, r4
	ldr r3, [r0, #0x00]
	movs r0, #0x07
	movs r1, #0x00
	movs r2, #0x00
	bl func_0809D2B0
	ldr r4, _0800BB14 @ =0x020348A0
	adds r0, r4, #0x0
	bl func_08000EA4
	adds r0, r4, #0x0
	bl func_08000EE0
_0800BAFC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0800BB04: .4byte 0x020348B4
_0800BB08: .4byte 0x09ED8644
_0800BB0C: .4byte 0x081309B0
_0800BB10: .4byte 0x081309D0
_0800BB14: .4byte 0x020348A0
.syntax divided
