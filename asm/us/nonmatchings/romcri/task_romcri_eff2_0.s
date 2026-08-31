.syntax unified
	.align 2, 0
	.global task_romcri_eff2_0
	.thumb
	.thumb_func
	.type task_romcri_eff2_0, %function
task_romcri_eff2_0: @ 0803FBDC
	push {r4, r5, lr}
	adds r5, r0, #0x0
	adds r4, r1, #0x0
	movs r0, #0x01
	movs r1, #0x00
	movs r2, #0x17
	movs r3, #0x0C
	bl SetupBg
	movs r1, #0x00
	movs r0, #0x00
	strh r0, [r5, #0x00]
	strb r1, [r5, #0x03]
	strb r4, [r5, #0x02]
	movs r0, #0x01
	bl func_0800501C
	movs r0, #0x00
	bl func_08007E68
	ldr r1, _0803FC4C @ =0x08F6DA04
	movs r0, #0x01
	movs r2, #0x20
	bl LoadBgPalette
	bl func_08007E7C
	movs r0, #0x01
	movs r1, #0x00
	bl SetBgPriority
	movs r0, #0x01
	movs r1, #0x10
	movs r2, #0x10
	bl func_080057A0
	ldr r1, _0803FC50 @ =0x08EE3064
	movs r2, #0xA2
	lsls r2, r2, #0x04
	movs r0, #0x01
	bl LoadBgTiles
	ldr r0, _0803FC54 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _0803FCA4
	ldrb r0, [r5, #0x02]
	cmp r0, #0x53
	beq _0803FC84
	cmp r0, #0x53
	bgt _0803FC58
	cmp r0, #0x2D
	beq _0803FC62
	b _0803FCFA
_0803FC4C: .4byte 0x08F6DA04
_0803FC50: .4byte 0x08EE3064
_0803FC54: .4byte 0x02039BB0
_0803FC58:
	cmp r0, #0xAD
	beq _0803FC94
	cmp r0, #0xD3
	beq _0803FC74
	b _0803FCFA
_0803FC62:
	ldr r1, _0803FC70 @ =0x0000FF9C
	movs r0, #0x01
	movs r2, #0x04
	bl SetBgScroll
	b _0803FCFA
	.byte 0x00, 0x00
_0803FC70: .4byte 0x0000FF9C
_0803FC74:
	ldr r1, _0803FC80 @ =0x0000FFB7
	movs r0, #0x01
	movs r2, #0x05
	bl SetBgScroll
	b _0803FCFA
_0803FC80: .4byte 0x0000FFB7
_0803FC84:
	ldr r1, _0803FC8C @ =0x0000FF9B
	ldr r2, _0803FC90 @ =0x0000FFEE
	b _0803FCE0
	.byte 0x00, 0x00
_0803FC8C: .4byte 0x0000FF9B
_0803FC90: .4byte 0x0000FFEE
_0803FC94:
	ldr r1, _0803FC9C @ =0x0000FFB5
	ldr r2, _0803FCA0 @ =0x0000FFED
	b _0803FCE0
	.byte 0x00, 0x00
_0803FC9C: .4byte 0x0000FFB5
_0803FCA0: .4byte 0x0000FFED
_0803FCA4:
	ldrb r0, [r5, #0x02]
	cmp r0, #0x53
	beq _0803FCDC
	cmp r0, #0x53
	bgt _0803FCB4
	cmp r0, #0x2D
	beq _0803FCBE
	b _0803FCFA
_0803FCB4:
	cmp r0, #0xAD
	beq _0803FCF0
	cmp r0, #0xD3
	beq _0803FCCC
	b _0803FCFA
_0803FCBE:
	ldr r1, _0803FCC4 @ =0x0000FF9C
	ldr r2, _0803FCC8 @ =0x0000FFFA
	b _0803FCE0
_0803FCC4: .4byte 0x0000FF9C
_0803FCC8: .4byte 0x0000FFFA
_0803FCCC:
	ldr r1, _0803FCD4 @ =0x0000FFB7
	ldr r2, _0803FCD8 @ =0x0000FFFB
	b _0803FCE0
	.byte 0x00, 0x00
_0803FCD4: .4byte 0x0000FFB7
_0803FCD8: .4byte 0x0000FFFB
_0803FCDC:
	ldr r1, _0803FCE8 @ =0x0000FF9B
	ldr r2, _0803FCEC @ =0x0000FFE4
_0803FCE0:
	movs r0, #0x01
	bl SetBgScroll
	b _0803FCFA
_0803FCE8: .4byte 0x0000FF9B
_0803FCEC: .4byte 0x0000FFE4
_0803FCF0:
	ldr r1, _0803FD00 @ =0x0000FFB5
	ldr r2, _0803FD04 @ =0x0000FFE3
	movs r0, #0x01
	bl SetBgScroll
_0803FCFA:
	pop {r4, r5}
	pop {r0}
	bx r0
_0803FD00: .4byte 0x0000FFB5
_0803FD04: .4byte 0x0000FFE3
.syntax divided
