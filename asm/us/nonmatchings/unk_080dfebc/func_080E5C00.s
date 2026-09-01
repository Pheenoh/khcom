.syntax unified
	.align 2, 0
	.global func_080E5C00
	.thumb
	.thumb_func
	.type func_080E5C00, %function
func_080E5C00: @ 080E5C00
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	ldr r0, _080E5C4C @ =0x0203C7AC
	ldr r0, [r0, #0x00]
	ldrb r4, [r0, #0x0D]
	lsls r4, r4, #0x03
	ldr r0, _080E5C50 @ =0x0984D134
	adds r4, r4, r0
	ldr r0, _080E5C54 @ =0x0203C590
	ldrb r0, [r0, #0x06]
	bl func_080DEE18
	adds r1, r0, #0x0
	ldr r2, _080E5C58 @ =0x02034F40
	ldrb r0, [r2, #0x00]
	ldrb r4, [r4, #0x01]
	cmp r0, r4
	bcs _080E5CC0
	ldrb r0, [r1, #0x0B]
	ldrb r1, [r2, #0x00]
	subs r0, r0, r1
	cmp r0, #0x00
	ble _080E5CC0
	ldr r1, _080E5C5C @ =0x09EF83F8
	lsls r0, r7, #0x02
	adds r0, r0, r1
	ldr r7, [r0, #0x00]
	cmp r6, #0x02
	beq _080E5C60
	cmp r6, #0x02
	ble _080E5C74
	cmp r6, #0x03
	beq _080E5C68
	b _080E5C74
_080E5C4C: .4byte 0x0203C7AC
_080E5C50: .4byte 0x0984D134
_080E5C54: .4byte 0x0203C590
_080E5C58: .4byte 0x02034F40
_080E5C5C: .4byte 0x09EF83F8
_080E5C60:
	adds r0, r5, #0x0
	bl func_080E59D8
	b _080E5C6E
_080E5C68:
	adds r0, r5, #0x0
	bl func_080E5AC8
_080E5C6E:
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	b _080E5C90
_080E5C74:
	adds r0, r5, #0x0
	bl func_080E5968
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, [r5, #0x08]
	ldr r1, [r5, #0x0C]
	ldr r2, _080E5CC8 @ =0x02039BA0
	ldr r3, [r2, #0x00]
	ldr r2, [r3, #0x18]
	ldr r3, [r3, #0x1C]
	bl GetAngle
	strb r0, [r5, #0x18]
_080E5C90:
	cmp r4, #0x00
	beq _080E5CC0
	ldr r2, _080E5CCC @ =0x02034F48
	ldr r0, _080E5CD0 @ =0x02034F40
	ldrb r1, [r0, #0x00]
	lsls r1, r1, #0x04
	adds r1, r1, r2
	adds r0, r5, #0x0
	adds r0, #0x08
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	movs r0, #0x00
	str r0, [r5, #0x1C]
	str r7, [r5, #0x00]
	str r0, [r5, #0x04]
	ldr r0, _080E5CC8 @ =0x02039BA0
	ldr r0, [r0, #0x00]
	adds r0, #0xB4
	ldr r1, [r7, #0x10]
	adds r2, r5, #0x0
	bl TaskCreate
_080E5CC0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080E5CC8: .4byte 0x02039BA0
_080E5CCC: .4byte 0x02034F48
_080E5CD0: .4byte 0x02034F40
.syntax divided
