.syntax unified
	.align 2, 0
	.global func_080E8E74
	.thumb
	.thumb_func
	.type func_080E8E74, %function
func_080E8E74: @ 080E8E74
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080E8E9C @ =0x00002710
	bl func_0811D7CC
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r1, _080E8EA0 @ =0x09EF8388
	ldr r0, _080E8EA4 @ =0x02039BB0
	ldrb r0, [r0, #0x0C]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r4, [r0, #0x00]
	b _080E8EFC
	.byte 0x00, 0x00
_080E8E9C: .4byte 0x00002710
_080E8EA0: .4byte 0x09EF8388
_080E8EA4: .4byte 0x02039BB0
_080E8EA8:
	ldrb r0, [r4, #0x00]
	lsls r0, r0, #0x02
	ldr r1, _080E8EB8 @ =0x0985814C
	adds r5, r0, r1
	cmp r6, #0x00
	beq _080E8EBC
	ldrh r0, [r4, #0x04]
	b _080E8EBE
_080E8EB8: .4byte 0x0985814C
_080E8EBC:
	ldrh r0, [r4, #0x02]
_080E8EBE:
	cmp r2, r0
	bcs _080E8EF4
	ldrb r0, [r5, #0x00]
	bl func_0800FC5C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080E8ED2
	adds r0, r5, #0x0
	b _080E8F04
_080E8ED2:
	ldrb r0, [r4, #0x00]
	cmp r0, #0x10
	bhi _080E8EE0
	ldr r0, _080E8EDC @ =0x0985814C
	b _080E8F04
_080E8EDC: .4byte 0x0985814C
_080E8EE0:
	cmp r0, #0x1E
	bhi _080E8EEC
	ldr r0, _080E8EE8 @ =0x0985819C
	b _080E8F04
_080E8EE8: .4byte 0x0985819C
_080E8EEC:
	ldr r0, _080E8EF0 @ =0x098581C8
	b _080E8F04
_080E8EF0: .4byte 0x098581C8
_080E8EF4:
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	adds r4, #0x08
_080E8EFC:
	ldrb r0, [r4, #0x00]
	cmp r0, #0x29
	bne _080E8EA8
	movs r0, #0x00
_080E8F04:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
