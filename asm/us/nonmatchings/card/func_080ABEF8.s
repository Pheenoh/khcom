.syntax unified
	.align 2, 0
	.global func_080ABEF8
	.thumb
	.thumb_func
	.type func_080ABEF8, %function
func_080ABEF8: @ 080ABEF8
	push {r4, r5, r6, lr}
	add sp, #-0x018
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	movs r6, #0x00
	ldr r1, _080ABF14 @ =0x02039DD4
	ldr r1, [r1, #0x00]
	adds r1, #0xD0
	ldrb r1, [r1, #0x00]
	cmp r1, #0x02
	bhi _080ABF18
	movs r0, #0x00
	b _080AC130
	.byte 0x00, 0x00
_080ABF14: .4byte 0x02039DD4
_080ABF18:
	ldr r3, [r4, #0x00]
	str r3, [sp, #0x000]
	ldr r2, [r4, #0x04]
	str r2, [sp, #0x004]
	ldr r1, [r4, #0x08]
	str r1, [sp, #0x008]
	lsls r2, r2, #0x0A
	orrs r2, r3
	movs r1, #0x80
	lsls r1, r1, #0x18
	orrs r2, r1
	ldr r1, _080ABF50 @ =0x80043D0F
	cmp r2, r1
	beq _080AC018
	cmp r2, r1
	bhi _080ABFA8
	ldr r1, _080ABF54 @ =0x80034CD3
	cmp r2, r1
	beq _080AC018
	cmp r2, r1
	bhi _080ABF74
	ldr r1, _080ABF58 @ =0x8002D4B5
	cmp r2, r1
	beq _080AC018
	cmp r2, r1
	bhi _080ABF60
	ldr r1, _080ABF5C @ =0x8002ACAB
	b _080AC014
_080ABF50: .4byte 0x80043D0F
_080ABF54: .4byte 0x80034CD3
_080ABF58: .4byte 0x8002D4B5
_080ABF5C: .4byte 0x8002ACAB
_080ABF60:
	ldr r1, _080ABF6C @ =0x8002FCBF
	cmp r2, r1
	beq _080AC018
	ldr r1, _080ABF70 @ =0x800324C9
	b _080AC014
	.byte 0x00, 0x00
_080ABF6C: .4byte 0x8002FCBF
_080ABF70: .4byte 0x800324C9
_080ABF74:
	ldr r1, _080ABF88 @ =0x8003C4F1
	cmp r2, r1
	beq _080AC018
	cmp r2, r1
	bhi _080ABF94
	ldr r1, _080ABF8C @ =0x800374DD
	cmp r2, r1
	beq _080AC018
	ldr r1, _080ABF90 @ =0x80039CE7
	b _080AC014
_080ABF88: .4byte 0x8003C4F1
_080ABF8C: .4byte 0x800374DD
_080ABF90: .4byte 0x80039CE7
_080ABF94:
	ldr r1, _080ABFA0 @ =0x8003ECFB
	cmp r2, r1
	beq _080AC018
	ldr r1, _080ABFA4 @ =0x80041505
	b _080AC014
	.byte 0x00, 0x00
_080ABFA0: .4byte 0x8003ECFB
_080ABFA4: .4byte 0x80041505
_080ABFA8:
	ldr r1, _080ABFC8 @ =0x80052D4B
	cmp r2, r1
	beq _080AC018
	cmp r2, r1
	bhi _080ABFEC
	ldr r1, _080ABFCC @ =0x8004B52D
	cmp r2, r1
	beq _080AC018
	cmp r2, r1
	bhi _080ABFD8
	ldr r1, _080ABFD0 @ =0x80046519
	cmp r2, r1
	beq _080AC018
	ldr r1, _080ABFD4 @ =0x80048D23
	b _080AC014
	.byte 0x00, 0x00
_080ABFC8: .4byte 0x80052D4B
_080ABFCC: .4byte 0x8004B52D
_080ABFD0: .4byte 0x80046519
_080ABFD4: .4byte 0x80048D23
_080ABFD8:
	ldr r1, _080ABFE4 @ =0x8004DD37
	cmp r2, r1
	beq _080AC018
	ldr r1, _080ABFE8 @ =0x80050541
	b _080AC014
	.byte 0x00, 0x00
_080ABFE4: .4byte 0x8004DD37
_080ABFE8: .4byte 0x80050541
_080ABFEC:
	ldr r1, _080AC000 @ =0x8005A569
	cmp r2, r1
	beq _080AC018
	cmp r2, r1
	bhi _080AC00C
	ldr r1, _080AC004 @ =0x80055555
	cmp r2, r1
	beq _080AC018
	ldr r1, _080AC008 @ =0x80057D5F
	b _080AC014
_080AC000: .4byte 0x8005A569
_080AC004: .4byte 0x80055555
_080AC008: .4byte 0x80057D5F
_080AC00C:
	ldr r1, _080AC054 @ =0x8005CD73
	cmp r2, r1
	beq _080AC018
	ldr r1, _080AC058 @ =0x800A7E9F
_080AC014:
	cmp r2, r1
	bne _080AC01E
_080AC018:
	str r2, [r4, #0x00]
	movs r1, #0x01
	strb r1, [r5, #0x00]
_080AC01E:
	adds r6, #0x01
	ldr r1, [sp, #0x008]
	lsls r1, r1, #0x0A
	ldr r2, [sp, #0x004]
	orrs r2, r1
	movs r1, #0x80
	lsls r1, r1, #0x18
	orrs r2, r1
	ldr r1, _080AC05C @ =0x80043D0F
	cmp r2, r1
	bne _080AC036
	b _080AC124
_080AC036:
	cmp r2, r1
	bhi _080AC0B4
	ldr r1, _080AC060 @ =0x80034CD3
	cmp r2, r1
	beq _080AC124
	cmp r2, r1
	bhi _080AC080
	ldr r1, _080AC064 @ =0x8002D4B5
	cmp r2, r1
	beq _080AC124
	cmp r2, r1
	bhi _080AC06C
	ldr r1, _080AC068 @ =0x8002ACAB
	b _080AC120
	.byte 0x00, 0x00
_080AC054: .4byte 0x8005CD73
_080AC058: .4byte 0x800A7E9F
_080AC05C: .4byte 0x80043D0F
_080AC060: .4byte 0x80034CD3
_080AC064: .4byte 0x8002D4B5
_080AC068: .4byte 0x8002ACAB
_080AC06C:
	ldr r1, _080AC078 @ =0x8002FCBF
	cmp r2, r1
	beq _080AC124
	ldr r1, _080AC07C @ =0x800324C9
	b _080AC120
	.byte 0x00, 0x00
_080AC078: .4byte 0x8002FCBF
_080AC07C: .4byte 0x800324C9
_080AC080:
	ldr r1, _080AC094 @ =0x8003C4F1
	cmp r2, r1
	beq _080AC124
	cmp r2, r1
	bhi _080AC0A0
	ldr r1, _080AC098 @ =0x800374DD
	cmp r2, r1
	beq _080AC124
	ldr r1, _080AC09C @ =0x80039CE7
	b _080AC120
_080AC094: .4byte 0x8003C4F1
_080AC098: .4byte 0x800374DD
_080AC09C: .4byte 0x80039CE7
_080AC0A0:
	ldr r1, _080AC0AC @ =0x8003ECFB
	cmp r2, r1
	beq _080AC124
	ldr r1, _080AC0B0 @ =0x80041505
	b _080AC120
	.byte 0x00, 0x00
_080AC0AC: .4byte 0x8003ECFB
_080AC0B0: .4byte 0x80041505
_080AC0B4:
	ldr r1, _080AC0D4 @ =0x80052D4B
	cmp r2, r1
	beq _080AC124
	cmp r2, r1
	bhi _080AC0F8
	ldr r1, _080AC0D8 @ =0x8004B52D
	cmp r2, r1
	beq _080AC124
	cmp r2, r1
	bhi _080AC0E4
	ldr r1, _080AC0DC @ =0x80046519
	cmp r2, r1
	beq _080AC124
	ldr r1, _080AC0E0 @ =0x80048D23
	b _080AC120
	.byte 0x00, 0x00
_080AC0D4: .4byte 0x80052D4B
_080AC0D8: .4byte 0x8004B52D
_080AC0DC: .4byte 0x80046519
_080AC0E0: .4byte 0x80048D23
_080AC0E4:
	ldr r1, _080AC0F0 @ =0x8004DD37
	cmp r2, r1
	beq _080AC124
	ldr r1, _080AC0F4 @ =0x80050541
	b _080AC120
	.byte 0x00, 0x00
_080AC0F0: .4byte 0x8004DD37
_080AC0F4: .4byte 0x80050541
_080AC0F8:
	ldr r1, _080AC10C @ =0x8005A569
	cmp r2, r1
	beq _080AC124
	cmp r2, r1
	bhi _080AC118
	ldr r1, _080AC110 @ =0x80055555
	cmp r2, r1
	beq _080AC124
	ldr r1, _080AC114 @ =0x80057D5F
	b _080AC120
_080AC10C: .4byte 0x8005A569
_080AC110: .4byte 0x80055555
_080AC114: .4byte 0x80057D5F
_080AC118:
	ldr r1, _080AC138 @ =0x8005CD73
	cmp r2, r1
	beq _080AC124
	ldr r1, _080AC13C @ =0x800A7E9F
_080AC120:
	cmp r2, r1
	bne _080AC130
_080AC124:
	lsls r1, r6, #0x02
	adds r1, r1, r4
	str r2, [r1, #0x00]
	adds r2, r5, r6
	movs r1, #0x01
	strb r1, [r2, #0x00]
_080AC130:
	add sp, #0x018
	pop {r4, r5, r6}
	pop {r1}
	bx r1
_080AC138: .4byte 0x8005CD73
_080AC13C: .4byte 0x800A7E9F
_080AC140:
.syntax divided
