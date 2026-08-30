.syntax unified
	.align 2, 0
	.global func_080E8C38
	.thumb
	.thumb_func
	.type func_080E8C38, %function
func_080E8C38: @ 080E8C38
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _080E8C50 @ =0x0203C7AC
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	bge _080E8C58
	b _080E8C7C
	.byte 0x00, 0x00
_080E8C50: .4byte 0x0203C7AC
_080E8C54:
	movs r0, #0x01
	b _080E8C7E
_080E8C58:
	movs r0, #0x00
	bl func_080DEDD8
	adds r1, r0, #0x0
	b _080E8C76
_080E8C62:
	ldrb r0, [r1, #0x01]
	cmp r0, #0xFF
	beq _080E8C74
	ldrb r0, [r1, #0x02]
	cmp r0, r5
	bne _080E8C74
	ldrb r0, [r1, #0x03]
	cmp r0, r4
	beq _080E8C54
_080E8C74:
	adds r1, #0x08
_080E8C76:
	ldrb r0, [r1, #0x00]
	cmp r0, #0x05
	bne _080E8C62
_080E8C7C:
	movs r0, #0x00
_080E8C7E:
	pop {r4, r5}
	pop {r1}
	bx r1
.syntax divided
