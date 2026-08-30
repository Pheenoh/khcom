.syntax unified
	.align 2, 0
	.global func_080D733C
	.thumb
	.thumb_func
	.type func_080D733C, %function
func_080D733C: @ 080D733C
	push {r4, lr}
	movs r0, #0x02
	bl func_08005130
	adds r2, r0, #0x0
	adds r2, #0x40
	ldr r4, _080D7388 @ =0x02039BB0
	movs r1, #0x84
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldrb r1, [r0, #0x00]
	adds r0, r2, #0x0
	movs r2, #0x02
	bl func_080D728C
	adds r2, r0, #0x0
	movs r3, #0x32
	ldsh r1, [r4, r3]
	movs r2, #0x03
	bl func_080D728C
	adds r2, r0, #0x0
	adds r0, r4, #0x0
	adds r0, #0xF8
	movs r3, #0x00
	ldsh r1, [r0, r3]
	adds r0, r2, #0x0
	movs r2, #0x03
	bl func_080D728C
	adds r2, r0, #0x0
	ldr r0, [r4, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _080D738C
	adds r2, #0x80
	b _080D739E
_080D7388: .4byte 0x02039BB0
_080D738C:
	adds r0, r4, #0x0
	adds r0, #0xFA
	movs r3, #0x00
	ldsh r1, [r0, r3]
	adds r0, r2, #0x0
	movs r2, #0x04
	bl func_080D728C
	adds r2, r0, #0x0
_080D739E:
	ldr r4, _080D73F4 @ =0x02039BB0
	movs r1, #0x80
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldr r1, [r0, #0x00]
	adds r0, r2, #0x0
	movs r2, #0x06
	bl func_080D728C
	adds r2, r0, #0x0
	movs r3, #0x82
	lsls r3, r3, #0x01
	adds r0, r4, r3
	ldr r1, [r0, #0x00]
	adds r0, r2, #0x0
	movs r2, #0x06
	bl func_080D728C
	adds r2, r0, #0x0
	ldr r0, [r4, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _080D73F8
	adds r2, #0xC0
	adds r0, r4, #0x0
	adds r0, #0xFE
	movs r3, #0x00
	ldsh r1, [r0, r3]
	adds r0, r2, #0x0
	movs r2, #0x02
	bl func_080D728C
	adds r2, r0, #0x0
	adds r0, r4, #0x0
	adds r0, #0xFC
	movs r3, #0x00
	ldsh r1, [r0, r3]
	adds r0, r2, #0x0
	movs r2, #0x03
	bl func_080D728C
	b _080D740A
_080D73F4: .4byte 0x02039BB0
_080D73F8:
	adds r2, #0x20
	movs r1, #0xBA
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldr r1, [r0, #0x00]
	adds r0, r2, #0x0
	movs r2, #0x05
	bl func_080D728C
_080D740A:
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
